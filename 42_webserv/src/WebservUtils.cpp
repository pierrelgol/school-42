/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WebservUtils.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 21:29:13 by pollivie          #+#    #+#             */
/*   Updated: 2025/01/11 22:49:24 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Webserv.hpp"

#include <iostream>
#include <ctime>
#include <unistd.h>


void logTimeEvent(const string &event_message) {
        static isize counter = 1;


        if (counter % 10 == 0) {
                std::time_t t       = std::time(NULL);
                struct tm  *tm_info = std::localtime(&t);
                char        formatted_time[20];
                strftime(formatted_time, sizeof(formatted_time), "%H:%M:%S", tm_info);
                std::cerr << COLOR_GREEN << "[LOG]" << COLOR_RESET << COLOR_CYAN << ": [webserv] " << formatted_time << COLOR_RESET << " : " << COLOR_YELLOW
                          << event_message << COLOR_RESET << std::endl;
                counter = 1;
        } else {
                counter++;
        }
}


void logEvent(Server *server, const string &event) {
        if (server) {
                fprintf(stderr,
                        COLOR_GREEN "[LOG]" COLOR_RESET COLOR_CYAN ": %s" COLOR_RESET " fd(%d): " COLOR_YELLOW "%s" COLOR_RESET "\n",
                        server->getServerPrettyName().c_str(),
                        server->getSocket(),
                        event.c_str());
        } else {
                fprintf(stderr,
                        COLOR_GREEN "[LOG]" COLOR_RESET COLOR_CYAN ": [webserv]" COLOR_RESET " [no server context]: " COLOR_YELLOW "%s" COLOR_RESET "\n",
                        event.c_str());
        }
        fflush(stderr);
}

bool Webserv::asyncRequestPending(i32 client) {

        Server *server = NULL;

        try {
                server = _clients_handler.at(client);
        } catch (const std::out_of_range &e) {
                logEvent(NULL, "Client FD: " + to_string(client) + " not found in clients handler map: " + string(e.what()));
                return false;
        } catch (const std::exception &e) {
                logEvent(NULL, "Unexpected exception while accessing client FD: " + to_string(client) + ": " + string(e.what()));
                return false;
        }

        if (!server) {
                logEvent(NULL, "Server is NULL for client FD: " + to_string(client));
                return false;
        }

        Cgi *cgi = server->getAsyncCgis(client);
        if (!cgi) {
                logEvent(server, "No CGI instance found for client FD: " + to_string(client));
                return false;
        }

        bool has_timed_out = cgi->hasTimeout(time(NULL), 60);
        logEvent(server, "Async request for client FD: " + to_string(client) + (has_timed_out ? " has timed out." : " is still pending."));
        return has_timed_out == false;
}


void Webserv::appendClient(i32 client_fd, Server *server) {
        LOG_STACK_TRACE();
        struct epoll_event ev;

        if (server == NULL) {
                close(client_fd);
                return;
        }

        ev.events  = EPOLLIN | EPOLLOUT;
        ev.data.fd = client_fd;
        if (epoll_ctl(_epfd, EPOLL_CTL_ADD, client_fd, &ev) == -1) {
                close(client_fd);
                return;
        }

        _clients_handler[client_fd] = server;
        _clients_fd.push_back(client_fd);
}

void Webserv::removeClient(i32 client_fd) {
        LOG_STACK_TRACE();
        logEvent(NULL, "Removing client FD: " + to_string(client_fd));

        struct epoll_event ev;
        i32                cgi_fd = 0;

        // Remove client FD from the tracked list
        for (vector< i32 >::iterator it = _clients_fd.begin(); it != _clients_fd.end(); it++) {
                if (*it == client_fd) {
                        _clients_fd.erase(it);
                        logEvent(NULL, "Removed client FD from tracked list: " + to_string(client_fd));
                        break;
                }
        }

        // Handle CGI associated with this client, if any
        if (_clients_handler.find(client_fd) != _clients_handler.end()) {
                Server *server = getServer(client_fd);
                if (server) {
                        Cgi *cgi = server->getAsyncCgis(client_fd);
                        if (cgi) {
                                cgi_fd = cgi->getReadFd();
                                logEvent(NULL, "Found associated CGI FD: " + to_string(cgi_fd));
                        }
                }

                // Remove client from server
                _clients_handler[client_fd]->removeClient(client_fd);
                _clients_handler.erase(client_fd);
                logEvent(NULL, "Removed client handler.");
        }

        // Remove CGI FD from the tracked list
        for (vector< i32 >::iterator it = _cgis_fd.begin(); it != _cgis_fd.end(); it++) {
                if (*it == cgi_fd) {
                        _cgis_fd.erase(it);
                        logEvent(NULL, "Removed CGI FD from tracked list: " + to_string(cgi_fd));
                        break;
                }
        }

        // Remove the client FD from epoll and close it
        ev.events  = EPOLLIN | EPOLLOUT;
        ev.data.fd = client_fd;
        if (epoll_ctl(_epfd, EPOLL_CTL_DEL, client_fd, &ev) == -1) {
                logEvent(NULL, "Failed to remove client FD from epoll: " + Error());
        }
        close(client_fd);
        logEvent(NULL, "Closed client FD: " + to_string(client_fd));
}


Server *Webserv::getServer(i32 fd) {
        for (usize i = 0; i < _servers.size(); i++) {
                if (_servers[i].getSocket() == fd) {
                        return &_servers[i];
                }
        }
        return NULL;
}

bool Webserv::isServer(i32 fd) {
        for (usize i = 0; i < _servers_fd.size(); i++) {
                if (_servers_fd[i] == fd) {
                        return true;
                }
        }
        return false;
}

bool Webserv::isClient(i32 fd) {
        for (usize i = 0; i < _clients_fd.size(); i++) {
                if (_clients_fd[i] == fd) {
                        return true;
                }
        }
        return false;
}

bool Webserv::isCgi(i32 fd) {
        for (usize i = 0; i < _cgis_fd.size(); i++) {
                if (_cgis_fd[i] == fd) {
                        return true;
                }
        }
        return false;
}
