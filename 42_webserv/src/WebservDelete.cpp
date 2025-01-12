/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WebservDelete.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 22:31:31 by pollivie          #+#    #+#             */
/*   Updated: 2025/01/11 22:49:29 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Webserv.hpp"
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>

bool Webserv::handleDeleteRequest(Request &request, Server &server, Response &response) {
        string requested_uri = request.getUri();
        string path_uri;
        string file_uri;
        string query_uri;

        logEvent(&server, "Handling DELETE request for URI: " + requested_uri);
        if (!parseUri(requested_uri, path_uri, file_uri, query_uri)) {
                response.emitError(400, "Error 400 : Bad Request", server);
                logEvent(&server, "Failed to parse URI: '" + requested_uri + "'. Sending 400 Bad Request.");
                return false;
        }
        logEvent(&server, "Parsed URI successfully. Path: '" + path_uri + "', File: '" + file_uri + "', Query: '" + query_uri + "'.");

        Location location;
        if (!server.getMatchingLocation(path_uri, location)) {
                response.emitError(404, "Error 404: Not Found", server);
                logEvent(&server, "No matching location found for path: '" + path_uri + "'. Sending 404 Not Found.");
                return false;
        }
        logEvent(&server, "Matched location: '" + location.getPath() + "' for path: '" + path_uri + "'.");

        if (!location.isMethodAllowed("DELETE")) {
                response.emitError(403, "Error 403: Forbidden", server);
                logEvent(&server, "DELETE method is not allowed for location: '" + location.getPath() + "'. Sending 403 Forbidden.");
                return false;
        }

        string full_path = joinPaths(location.getRoot(), path_uri.substr(location.getPath().length()));
        if (!file_uri.empty()) {
                full_path = joinPaths(full_path, file_uri);
        }
        logEvent(&server, "Constructed file path: '" + full_path + "'.");

        struct stat file_info;
        if (stat(full_path.c_str(), &file_info) != 0) {
                response.emitError(404, "Error 404: Not Found", server);
                logEvent(&server, "Resource not found: '" + full_path + "'. Sending 404 Not Found.");
                return false;
        }

        if (S_ISDIR(file_info.st_mode)) {
                if (rmdir(full_path.c_str()) != 0) {
                        response.emitError(500, "Error 500: Internal Server Error", server);
                        logEvent(&server, "Failed to delete directory: '" + full_path + "'. Error: " + strerror(errno));
                        return false;
                }
        } else {
                if (unlink(full_path.c_str()) != 0) {
                        response.emitError(500, "Error 500: Internal Server Error", server);
                        logEvent(&server, "Failed to delete file: '" + full_path + "'. Error: " + strerror(errno));
                        return false;
                }
        }

        response.setInfo("Status", "204");
        response.setInfo("Reason", "No Content");
        logEvent(&server, "Successfully deleted resource: '" + full_path + "'.");
        return true;


        return false;
}
