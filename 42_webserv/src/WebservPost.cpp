/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WebservPost.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 22:31:19 by pollivie          #+#    #+#             */
/*   Updated: 2025/01/11 22:49:19 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Webserv.hpp"
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

bool Webserv::handlePostRequest(Request &request, Server &server, Response &response) {
        string requested_uri = request.getUri();
        string path_uri;
        string file_uri;
        string query_uri;

        logEvent(&server, "Handling POST request for URI: " + requested_uri);
        // Parse URI
        if (!parseUri(requested_uri, path_uri, file_uri, query_uri)) {
                response.emitError(400, "Error 400 : Bad Request", server);
                logEvent(&server, "Failed to parse URI: '" + requested_uri + "'. Sending 400 Bad Request.");
                return false;
        }
        logEvent(&server, "Parsed URI successfully. Path: '" + path_uri + "', File: '" + file_uri + "', Query: '" + query_uri + "'.");

        // Match Location
        Location location;
        // Match location for CGI or static content
        string combined_uri = joinPaths(path_uri, file_uri);

        // Check if the combined URI matches a CGI location
        if (server.getMatchingLocation(combined_uri, location)) {
                string cgi_path = location.getCgiPath();
                if (!cgi_path.empty() && combined_uri == location.getPath()) {
                        logEvent(&server, "The path requested is for CGI execution: '" + combined_uri + "'.");
                        response.setAsyncCgi(location.getCgiPath(), query_uri);
                        return true;
                }
        }


        if (!server.getMatchingLocation(path_uri, location)) {
                response.emitError(404, "Error 404: Not Found", server);
                logEvent(&server, "No matching location found for path: '" + path_uri + "'. Sending 404 Not Found.");
                return false;
        }
        logEvent(&server, "Matched location: '" + location.getPath() + "' for path: '" + path_uri + "'.");

        // Check method allowance
        if (!location.isMethodAllowed("POST")) {
                response.emitError(403, "Error 403: Forbidden", server);
                logEvent(&server, "POST method is not allowed for location: '" + location.getPath() + "'. Sending 403 Forbidden.");
                return false;
        }

        if (request.getBodySize() > server.getMaxBodySize()) {
                response.emitError(413, "Error 413: Payload Too Large", server);
                logEvent(&server, "Payload exceeds client_max_body_size for location: '" + location.getPath() + "'. Sending 413.");
                return false;
        }

        // Construct file path
        string full_path = joinPaths(location.getRoot(), path_uri.substr(location.getPath().length()));
        if (!file_uri.empty()) {
                full_path = joinPaths(full_path, file_uri);
        }
        logEvent(&server, "Constructed file path: '" + full_path + "'.");


        // Handle POST data
        string content_type = request.getHeader("Content-Type");
        if (content_type == "application/x-www-form-urlencoded") {
                // Write key-value pairs to file
                int fd = open(full_path.c_str(), O_CREAT | O_WRONLY | O_APPEND, 0644);
                if (fd == -1) {
                        response.emitError(500, "Error 500: Internal Server Error", server);
                        logEvent(&server, "Failed to open file for writing: '" + full_path + "'. Sending 500.");
                        return false;
                }

                for (map< string, string >::const_iterator it = request.getPostKv().begin(); it != request.getPostKv().end(); it++) {
                        string entry = it->first + "=" + it->second + "\n";
                        if (write(fd, entry.c_str(), entry.size()) == -1) {
                                close(fd);
                                response.emitError(500, "Error 500: Internal Server Error", server);
                                logEvent(&server, "Failed to write to file: '" + full_path + "'. Sending 500.");
                                return false;
                        }
                }
                close(fd);

        } else if (content_type.find("multipart/form-data") != string::npos) {
                struct stat path_stat;
                if (stat(full_path.c_str(), &path_stat) != 0) {
                        response.emitError(404, "Error 404: Path Not Found", server);
                        logEvent(&server, "Path does not exist: '" + full_path + "'. Sending 404.");
                        return false;
                }

                if (S_ISREG(path_stat.st_mode)) {
                        // full_path is a file
                        if (request.getFiles().size() != 1) {
                                response.emitError(400, "Error 400: Bad Request", server);
                                logEvent(&server, "Multiple files provided, but target is a single file: '" + full_path + "'. Sending 400.");
                                return false;
                        }

                        const FileData &file = request.getFiles().begin()->second;
                        int             fd   = open(full_path.c_str(), O_CREAT | O_WRONLY | O_TRUNC, 0644);
                        if (fd == -1) {
                                response.emitError(500, "Error 500: Internal Server Error", server);
                                logEvent(&server, "Failed to open file for writing: '" + full_path + "'. Sending 500.");
                                return false;
                        }

                        if (write(fd, file._content.c_str(), file._content.size()) == -1) {
                                close(fd);
                                response.emitError(500, "Error 500: Internal Server Error", server);
                                logEvent(&server, "Failed to write to file: '" + full_path + "'. Sending 500.");
                                return false;
                        }
                        close(fd);
                } else if (S_ISDIR(path_stat.st_mode)) {
                        // full_path is a directory
                        for (map< string, FileData >::const_iterator it = request.getFiles().begin(); it != request.getFiles().end(); ++it) {
                                const FileData &file      = it->second;
                                string          file_path = joinPaths(full_path, file._filename);
                                int             fd        = open(file_path.c_str(), O_CREAT | O_WRONLY | O_TRUNC, 0644);
                                if (fd == -1) {
                                        response.emitError(500, "Error 500: Internal Server Error", server);
                                        logEvent(&server, "Failed to open file for writing: '" + file_path + "'. Sending 500.");
                                        return false;
                                }

                                if (write(fd, file._content.c_str(), file._content.size()) == -1) {
                                        close(fd);
                                        response.emitError(500, "Error 500: Internal Server Error", server);
                                        logEvent(&server, "Failed to write to file: '" + file_path + "'. Sending 500.");
                                        return false;
                                }
                                close(fd);
                                logEvent(&server, "File successfully written: '" + file_path + "'.");
                        }
                } else {
                        // Not a regular file or directory
                        response.emitError(400, "Error 400: Bad Request", server);
                        logEvent(&server, "Invalid path type for: '" + full_path + "'. Sending 400.");
                        return false;
                }

                // Generate success response
                response.setInfo("Status", "201");
                response.setInfo("Reason", "POST request processed successfully.");
                logEvent(&server, "POST request handled successfully. Sending 201 Created.");
                return true;
        } else {
                response.emitError(415, "Error 415: Unsupported Media Type", server);
                logEvent(&server, "Unsupported Content-Type: '" + content_type + "'. Sending 415.");
                return false;
        }

        // Generate success response
        response.setInfo("Status", "201");
        response.setInfo("Reason", "POST request processed successfully.");
        logEvent(&server, "POST request handled successfully. Sending 201 Created.");
        return true;
}
