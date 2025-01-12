/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cgi.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:53:11 by pollivie          #+#    #+#             */
/*   Updated: 2025/01/12 14:53:12 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cgi.hpp"
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include "Request.hpp"

#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <vector>
#include <cstring>
#include <ctime>
#include <string>

Cgi::Cgi(const string &method, int client, const string &path, const string &args, Request &request)
    : _client(client), _pid(-1), _fd(-1), _since(time(NULL)), _path(path), _args(args), _method(method), _request(request) {
        logTimeEvent("Cgi instance created for path: " + path + ", with args: " + args);
}

Cgi::~Cgi() {
        logTimeEvent("Cgi closing...");
        cleanup();
}

bool Cgi::hasTimeout(time_t now, time_t timeout) const {
        LOG_STACK_TRACE();
        return (now - _since) > timeout;
}

int Cgi::getReadFd() const {
        return _fd;
}

int Cgi::getClientFd() const {
        return _client;
}

bool Cgi::start(Request &request) {
        LOG_STACK_TRACE();
        logEvent(NULL, "Starting CGI process for path: " + _path + ", with method: " + _method);

        int out_pipes[2];
        int in_pipes[2];

        _since = time(NULL);
        // Create pipe for reading CGI stdout
        if (pipe(out_pipes) == -1) {
                logEvent(NULL, "Failed to create output pipe for CGI process. Error: " + string(strerror(errno)));
                return false;
        }
        // Create pipe for writing CGI stdin if POST
        if (_method == "POST" && pipe(in_pipes) == -1) {
                logEvent(NULL, "Failed to create input pipe for CGI process. Error: " + string(strerror(errno)));
                close(out_pipes[0]);
                close(out_pipes[1]);
                return false;
        }

        pid_t temp_pid = fork();
        if (temp_pid < 0) {
                logEvent(NULL, "Fork failed for CGI process. Error: " + string(strerror(errno)));
                close(out_pipes[0]);
                close(out_pipes[1]);
                if (_method == "POST") {
                        close(in_pipes[0]);
                        close(in_pipes[1]);
                }
                return false;
        }

        if (temp_pid == 0) {
                // Child Process
                logEvent(NULL, "In child process for CGI.");

                // Redirect stdout to output pipe and close both ends appropriately
                if (dup2(out_pipes[1], STDOUT_FILENO) == -1) {
                        _exit(1);
                }
                close(out_pipes[0]);
                close(out_pipes[1]);

                if (_method == "POST") {
                        // Redirect stdin to input pipe
                        if (dup2(in_pipes[0], STDIN_FILENO) == -1) {
                                _exit(1);
                        }
                        close(in_pipes[1]);
                        close(in_pipes[0]);
                }

                // Build argument vector and environment variables
                vector< const char * > argv;
                argv.push_back(_path.c_str());
                argv.push_back(NULL);
                char **envp = build_env(request);

                // Execute the CGI script
                logEvent(NULL, "Executing CGI script with execve. Path: " + _path);
                if (execve(_path.c_str(), const_cast< char *const * >(argv.data()), const_cast< char *const * >(envp)) == -1) {
                        logEvent(NULL, "Execve failed for CGI process. Path: " + _path + ", Error: " + string(strerror(errno)));
                        _exit(1);
                }
        } else {
                // Parent Process
                logEvent(NULL, "CGI process started successfully with PID: " + to_string(temp_pid));

                // Close parent's unneeded descriptor ends
                close(out_pipes[1]); // Parent reads from out_pipes[0]

                if (_method == "POST") {
                        close(in_pipes[0]); // Parent writes to in_pipes[1]

                        // Write the entire request body in a loop
                        const string &body          = request.getBody();
                        ssize_t       total_written = 0;
                        ssize_t       body_size     = body.size();
                        const char   *buf           = body.c_str();
                        while (total_written < body_size) {
                                ssize_t n = write(in_pipes[1], buf + total_written, body_size - total_written);
                                if (n <= 0) {
                                        logEvent(NULL, "Failed to write request body to pipe for CGI process. Error: " + string(strerror(errno)));
                                        close(in_pipes[1]);
                                        close(out_pipes[0]);
                                        return false;
                                }
                                total_written += n;
                        }
                        close(in_pipes[1]);
                }

                // Set the output descriptor to non-blocking mode
                // int flags = fcntl(out_pipes[0], F_GETFL, 0);
                // if (flags == -1) {
                //         logEvent(NULL, "Failed to get flags for CGI output FD. Error: " + string(strerror(errno)));
                //         close(out_pipes[0]);
                //         return false;
                // }
                // if (fcntl(out_pipes[0], F_SETFL, flags | O_NONBLOCK) == -1) {
                //         logEvent(NULL, "Failed to set non-blocking flag on CGI output FD. Error: " + string(strerror(errno)));
                //         close(out_pipes[0]);
                //         return false;
                // }

                // Save info for epoll monitoring
                _fd  = out_pipes[0];
                _pid = temp_pid;
                logEvent(NULL, "CGI output FD set to non-blocking and added for epoll monitoring.");

                // At this point, registration of _fd with epoll should occur elsewhere in your code.
        }
        return true;
}

char **Cgi::build_env(Request &request) {
        LOG_STACK_TRACE();

        string           path, file, arg;
        vector< string > env_vars;
        parseUri(request.getUri(), path, file, arg);
        // Common CGI environment variables
        env_vars.push_back("GATEWAY_INTERFACE=CGI/1.1");
        env_vars.push_back("SERVER_PROTOCOL=HTTP/1.1");
        env_vars.push_back("REQUEST_METHOD=" + _method);
        env_vars.push_back("SCRIPT_FILENAME=" + _path);
        env_vars.push_back("QUERY_STRING=" + arg);
        env_vars.push_back("CONTENT_TYPE=" + request.getHeader("Content-Type"));
        env_vars.push_back("CONTENT_LENGTH=" + string(request.getHeader("Content-Length")));
        env_vars.push_back("SERVER_NAME=" + request.getHeader("Host"));
        string host  = request.getHeader("Host");
        size_t colon = host.find(":");
        if (colon != string::npos) {
                env_vars.push_back("SERVER_PORT=" + host.substr(colon + 1));
        } else {
                env_vars.push_back("SERVER_PORT=8088");
        }

        // Convert to char**
        char **envp = new char *[env_vars.size() + 1];
        for (size_t i = 0; i < env_vars.size(); ++i) {
                envp[i] = strdup(env_vars[i].c_str());
        }
        envp[env_vars.size()] = NULL;
        return envp;
}

void Cgi::cleanup() {
        if (_fd != -1) {
                close(_fd);
                _fd = -1;
        }

        if (_pid > 0) {
                int status;
                // Note: Using WNOHANG returns immediately if the child hasn't ended.
                // Adjust waiting strategy if a blocking call is acceptable.
                waitpid(_pid, &status, WNOHANG);
                logTimeEvent("CGI process with PID " + to_string(_pid) + " reaped (or still running).");
        }

        logTimeEvent("Cgi resources cleaned up.");
}
