/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WebservGet.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 22:31:09 by pollivie          #+#    #+#             */
/*   Updated: 2025/01/11 22:49:40 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Webserv.hpp"
#include <sys/wait.h>

bool Webserv::handleGetRequest(Request &request, Server &server, Response &response) {
        string requested_uri = request.getUri();
        string path_uri;
        string file_uri;
        string query_uri;

        logEvent(&server, "Handling GET request for URI: " + requested_uri);

        // Parse URI
        if (!parseUri(requested_uri, path_uri, file_uri, query_uri)) {
                response.emitError(400, "Error 400 : Bad Request", server);
                logEvent(&server, "Failed to parse URI: '" + requested_uri + "'. Sending 400 Bad Request.");
                return false;
        }
        logEvent(&server, "Parsed URI successfully. Path: '" + path_uri + "', File: '" + file_uri + "', Query: '" + query_uri + "'.");

        // Match location for CGI or static content
        string   combined_uri = joinPaths(path_uri, file_uri);
        Location location;

        // Check if the combined URI matches a CGI location
        if (server.getMatchingLocation(combined_uri, location)) {
                string cgi_path = location.getCgiPath();
                if (!cgi_path.empty() && combined_uri == location.getPath()) {
                        logEvent(&server, "The path requested is for CGI execution: '" + combined_uri + "'.");
                        response.setAsyncCgi(location.getCgiPath(), query_uri);
                        return true;
                }
        }

        // Match location for static content
        if (!server.getMatchingLocation(path_uri, location)) {
                response.emitError(404, "Error 404: Not Found", server);
                logEvent(&server, "No matching location found for path: '" + path_uri + "'. Sending 404 Not Found.");
                return false;
        }
        logEvent(&server, "Matched location: '" + location.getPath() + "' for path: '" + path_uri + "'.");

        // Check method allowance
        if (!location.isMethodAllowed("GET")) {
                response.emitError(403, "Error 403: Forbidden", server);
                logEvent(&server, "GET method is not allowed for location: '" + location.getPath() + "'. Sending 403 Forbidden.");
                return false;
        }

        // Construct file path
        string path = joinPaths(location.getRoot(), path_uri.substr(location.getPath().length()));
        if (!file_uri.empty()) {
                path = joinPaths(path, file_uri);
        }
        logEvent(&server, "Constructed file path: '" + path + "'.");

        // Handle directory case
        if (isDirectory(path)) {
                logEvent(&server, "Path is a directory: '" + path + "'.");
                if (!location.getIndex().empty()) {
                        path = joinPaths(path, location.getIndex());
                        logEvent(&server, "Using index file: '" + location.getIndex() + "' for directory.");
                } else if (location.isAutoIndexEnabled()) {
                        response.setBody(generateDirectoryListing(path));
                        response.setHeader("Content-Type", "text/html");
                        logEvent(&server, "Autoindex is enabled. Sending directory listing for: '" + path + "'.");
                        return response.isSucessful();
                } else {
                        response.emitError(403, "Error 403: Forbidden", server);
                        logEvent(&server, "Directory listing is not allowed and no index file found for: '" + path + "'. Sending 403 Forbidden.");
                        return false;
                }
        }

        // Check if file exists in location
        if (!location.locationContainsFile(path)) {
                response.emitError(404, "Error 404: Not Found", server);
                logEvent(&server, "File not found in location: '" + path + "'. Sending 404 Not Found.");
                return false;
        }

        // Read file contents
        string file_buffer;
        isize  rbytes = openReadAll(path, file_buffer);
        if (rbytes <= 0) {
                response.emitError(500, "Error 500: Internal Server Error", server);
                logEvent(&server, "Failed to read file: '" + path + "'. Sending 500 Internal Server Error.");
                return false;
        }
        logEvent(&server, "Successfully read file: '" + path + "' (" + to_string(rbytes) + " bytes).");

        // Prepare and send response
        response.setBody(file_buffer);
        response.setHeader("Content-Type", determineContentType(path));
        response.setHeader("Content-Length", to_string(file_buffer.size()));
        logEvent(&server, "Response prepared. Content-Type: '" + determineContentType(path) + "', Content-Length: " + to_string(file_buffer.size()) + ".");

        return response.isSucessful();
}
