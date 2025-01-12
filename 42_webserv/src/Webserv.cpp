/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Webserv.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 12:10:33 by pollivie          #+#    #+#             */
/*   Updated: 2025/01/11 22:49:07 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Webserv.hpp"

static bool should_stop = false;
static void signalHandler(i32 sig) {
        (void)sig;
        should_stop = true;
}

Webserv::Webserv() : _epfd(-1), _nfds(0), _events(), _ev(), _servers(), _servers_fd(), _clients_fd(), _cgis_fd(), _clients_handler(), _cgi_handler() {
        LOG_STACK_TRACE();
}

Webserv::Webserv(const vector< Server > &servers) : _epfd(-1), _nfds(0), _events(), _ev(), _servers(servers), _servers_fd(), _clients_fd(), _clients_handler() {
        LOG_STACK_TRACE();
}

Webserv::Webserv(const Webserv &rhs) {
        LOG_STACK_TRACE();
        *this = rhs;
}

Webserv &Webserv::operator=(const Webserv &rhs) {
        if (this != &rhs) {
                _epfd            = rhs._epfd;
                _nfds            = rhs._nfds;
                _ev              = rhs._ev;
                _servers         = rhs._servers;
                _servers_fd      = rhs._servers_fd;
                _clients_fd      = rhs._clients_fd;
                _cgis_fd         = rhs._cgis_fd;
                _clients_handler = rhs._clients_handler;
                _cgi_handler     = rhs._cgi_handler;
                memcpy(_events, rhs._events, sizeof(struct epoll_event) * SERVER_MAX_EVENTS);
        }
        return *this;
}

Webserv::~Webserv() {
        LOG_STACK_TRACE();
}

void Webserv::setupSignalHandling() {
        LOG_STACK_TRACE();
        struct sigaction sa;
        memset(&sa, 0, sizeof(struct sigaction));
        sa.sa_handler = signalHandler;
        sa.sa_flags   = SA_RESETHAND;

        if (sigaction(SIGINT, &sa, NULL) == -1) {
                throw WebservError::UnexpectedException(": failed to handle SIGINT :" + Error());
        }

        if (sigaction(SIGQUIT, &sa, NULL) == -1) {
                throw WebservError::UnexpectedException(": failed to handle SIGQUIT :" + Error());
        }
}

void Webserv::setupEpollInstance() {
        LOG_STACK_TRACE();
        _epfd = epoll_create1(0);
        if (_epfd == -1) {
                throw WebservError::NetworkException(": failed to init Epoll instance : " + Error());
        }
        memset(_events, 0, sizeof(struct epoll_event) * SERVER_MAX_EVENTS);
        memset(&_ev, 0, sizeof(struct epoll_event));
}

void Webserv::setupServers() {
        LOG_STACK_TRACE();

        for (usize i = 0; i < _servers.size(); i++) {
                if (_servers[i].init() == false) {
                        logEvent(&_servers[i], "failed to setup server");
                        throw WebservError::NetworkException(": failed to setup server : " + Error());
                }

                _ev.events  = EPOLLIN;
                _ev.data.fd = _servers[i].getSocket();
                if (epoll_ctl(_epfd, EPOLL_CTL_ADD, _ev.data.fd, &_ev) == -1) {
                        logEvent(&_servers[i], "failed to register server to Epoll");
                        throw WebservError::NetworkException(": failed to register server to Epoll : " + Error());
                }
                _servers_fd.push_back(_ev.data.fd);
                logEvent(&_servers[i], "waiting for events...");
        }
}

void Webserv::startWebserver() {
        LOG_STACK_TRACE();
        logEvent(NULL, "Starting web server...");

        try {
                setupSignalHandling();
                logEvent(NULL, "Signal handling setup complete.");

                setupEpollInstance();
                logEvent(NULL, "Epoll instance setup complete.");

                setupServers();
                logEvent(NULL, "Servers setup complete.");
        } catch (const WebservError::BaseException &e) {
                logEvent(NULL, "Failed to initialize web server: " + string(e.what()));
                closeWebserver();
                throw;
        }

        while (!should_stop) {
                _nfds = epoll_wait(_epfd, _events, SERVER_MAX_EVENTS, SERVER_MAX_TIMEOUT);
                logTimeEvent("Waiting for events...");

                if (_nfds == -1) {
                        if (errno == EINTR) {
                                logEvent(NULL, "Epoll wait interrupted by signal, retrying...");
                                continue;
                        }
                        logEvent(NULL, "Epoll wait failed: " + Error());
                        closeWebserver();
                        throw WebservError::NetworkException("Epoll wait failed: " + Error());
                }

                for (usize i = 0; i < static_cast< usize >(_nfds); i++) {
                        const struct epoll_event event = _events[i];
                        const i32                fd    = event.data.fd;

                        if (isServer(fd)) {
                                Server *server = getServer(fd);
                                if (!server) {
                                        logEvent(NULL, "getServer returned NULL for fd(" + to_string(fd) + "). Shutting down.");
                                        closeWebserver();
                                        throw WebservError::UnexpectedException("getServer returned NULL.");
                                }

                                struct sockaddr_in addr    = server->getAddress();
                                socklen_t          addrlen = sizeof(addr);
                                i32                client  = accept(server->getSocket(), (struct sockaddr *)&addr, &addrlen);

                                if (client == -1) {
                                        if (errno != EAGAIN && errno != EWOULDBLOCK) {
                                                logEvent(server, "Accept failed: " + Error());
                                        }
                                        continue;
                                }

                                if (fcntl(client, F_SETFL, O_NONBLOCK) == -1) {
                                        logEvent(server, "Failed to set client fd(" + to_string(client) + ") to non-blocking: " + Error());
                                        close(client);
                                        continue;
                                }

                                appendClient(client, server);
                                logEvent(server, "Accepted new client: fd(" + to_string(client) + ").");
                        } else if (isClient(fd)) {
                                if (!_clients_handler[fd]) {
                                        logEvent(NULL, "No handler found for client fd(" + to_string(fd) + "). Removing client.");
                                        removeClient(fd);
                                        continue;
                                }

                                if (asyncRequestPending(fd)) {
                                        logEvent(_clients_handler[fd], "Async request pending for client fd(" + to_string(fd) + ").");
                                        continue;
                                } else if (!handleClientRequest(fd, *_clients_handler[fd])) {
                                        logEvent(_clients_handler[fd], "Failed to handle client request. Removing client fd(" + to_string(fd) + ").");
                                        removeClient(fd);
                                } else {
                                        Server *server = _clients_handler[fd];
                                        if (!server) {
                                                logEvent(NULL, "Server not found for client fd(" + to_string(fd) + ").");
                                                continue;
                                        }

                                        Cgi *cgi = server->getAsyncCgis(fd);
                                        if (!cgi) {
                                                logEvent(server, "No associated CGI for client fd(" + to_string(fd) + ").");
                                                continue;
                                        }

                                        // if (fcntl(cgi->getReadFd(), F_SETFD, O_NONBLOCK) == -1) {
                                        //         logEvent(server, "failed to put CGI O_NONBLOCK for client fd(" + to_string(fd) + ").");
                                        //         continue;
                                        // }

                                        struct epoll_event ev;
                                        ev.events  = EPOLLIN;
                                        ev.data.fd = cgi->getReadFd();

                                        if (epoll_ctl(_epfd, EPOLL_CTL_ADD, cgi->getReadFd(), &ev) == -1) {
                                                logEvent(server, "Failed to add CGI fd(" + to_string(cgi->getReadFd()) + ") to epoll: " + Error());
                                                continue;
                                        }

                                        _cgis_fd.push_back(cgi->getReadFd());
                                        _cgi_handler[cgi->getReadFd()] = server;
                                        logEvent(server, "Registered CGI fd(" + to_string(cgi->getReadFd()) + ") with epoll.");
                                }
                        } else if (isCgi(fd)) {
                                Server *server = _cgi_handler[fd];
                                if (!server) {
                                        logEvent(NULL, "No server found for CGI fd(" + to_string(fd) + ").");
                                        continue;
                                }

                                Cgi *cgi = server->getCgiByCgiFd(fd);
                                if (!cgi) {
                                        logEvent(server, "No CGI instance found for fd(" + to_string(fd) + ").");
                                        continue;
                                }

                                string cgi_output;
                                isize  rbytes = readAll(fd, cgi_output);
                                if (rbytes == -1) {
                                        logEvent(server, "Failed to read from CGI fd(" + to_string(fd) + "): " + Error());
                                        continue;
                                }
                                println("CGI OUTPUT : '" + cgi_output + "'");
                                Response response = server->getAsyncResponses(cgi->getClientFd());
                                response.setBody(cgi_output);
                                response.setHeader("Content-Type", "text/html");
                                response.setHeader("Content-Length", to_string(cgi_output.size()));
                                response.setInfo("Status", "200");
                                response.setInfo("Reason", "OK");
                                println("server sent -->" + response.getResponse());
                                sendAll(cgi->getClientFd(), response.getResponse());
                                logEvent(server, "Sent CGI response to client fd(" + to_string(cgi->getClientFd()) + ").");
                                removeClient(cgi->getClientFd());
                        }
                }
        }

        logEvent(NULL, "Stopping web server...");
        closeWebserver();
}



void Webserv::closeWebserver() {
        LOG_STACK_TRACE();
        logEvent(NULL, "Closing web server...");

        // Deinitialize all servers
        for (usize i = 0; i < _servers.size(); i++) {
                _servers[i].deinit();
                logEvent(&_servers[i], "Server deinitialized.");
        }

        // Remove all server file descriptors
        for (usize i = 0; i < _servers_fd.size(); i++) {
                if (epoll_ctl(_epfd, EPOLL_CTL_DEL, _servers_fd[i], NULL) == -1) {
                        logEvent(NULL, "Failed to remove server FD from epoll: " + Error());
                }
                close(_servers_fd[i]);
                logEvent(NULL, "Closed server FD: " + to_string(_servers_fd[i]));
        }

        // Remove all client file descriptors
        for (usize i = 0; i < _clients_fd.size(); i++) {
                if (epoll_ctl(_epfd, EPOLL_CTL_DEL, _clients_fd[i], NULL) == -1) {
                        logEvent(NULL, "Failed to remove client FD from epoll: " + Error());
                }
                close(_clients_fd[i]);
                logEvent(NULL, "Closed client FD: " + to_string(_clients_fd[i]));
        }

        // Remove all CGI file descriptors
        for (usize i = 0; i < _cgis_fd.size(); i++) {
                if (epoll_ctl(_epfd, EPOLL_CTL_DEL, _cgis_fd[i], NULL) == -1) {
                        logEvent(NULL, "Failed to remove CGI FD from epoll: " + Error());
                }
                close(_cgis_fd[i]);
                logEvent(NULL, "Closed CGI FD: " + to_string(_cgis_fd[i]));
        }

        // Close the epoll instance
        close(_epfd);
        logEvent(NULL, "Closed epoll FD.");
}


bool Webserv::handleClientRequest(i32 client_fd, Server &server) {
        LOG_STACK_TRACE();
        Request  request;
        Response response;
        string   buffer;

        isize    rbytes = recvAll(client_fd, buffer);
        if (rbytes == -1) {
                logEvent(&server, "recvAll failed for client_fd(" + to_string(client_fd) + ")");
                return false;
        } else if (rbytes == 0) {
                logEvent(&server, "client closed connection on fd(" + to_string(client_fd) + ")");
                return false;
        }

        if (!request.parseClientRequest(buffer)) {
                logEvent(&server, "failed to parse client request");
                response.emitError(request.getErrorCode(), request.getErrorMessage(), server);
                return response.isSucessful();
        } else {
                logEvent(&server, "client send a request");
                request.print();
        }

        string method = request.getMethod();
        if (method != "GET" and method != "POST" and method != "DELETE") {
                logEvent(&server, "unsupported method received: " + method);
                response.emitError(501, "Error 501 : Not Implemented", server);
                return false;
        }

        usize body_size = request.getBodySize();
        if (method == "GET" and body_size > server.getMaxBodySize()) {
                logEvent(&server, "GET request exceeds maximum body size");
                response.emitError(507, "Error 507 : Insufficient Storage", server);
                return false;
        } else if (method == "POST" and to_number< usize >(request.getHeader("Content-Length")) > server.getMaxBodySize()) {
                logEvent(&server, "POST request exceeds maximum body size");
                response.emitError(507, "Error 507 : Insufficient Storage", server);
                return false;
        }

        response = serverRespond(request, server);
        if (response.isAsync()) {
                server.addAsyncCgi(request, request.getMethod(), client_fd, response);
                return true;
        }

        return sendAll(client_fd, response.getResponse());
}

Response Webserv::serverRespond(Request &request, Server &server) {
        LOG_STACK_TRACE();
        Response response;
        if (request.getMethod() == "GET") {
                if (!handleGetRequest(request, server, response)) {
                        logEvent(&server, "GET request handling failed");
                }
        } else if (request.getMethod() == "POST") {
                if (!handlePostRequest(request, server, response)) {
                        logEvent(&server, "POST request handling failed");
                }
        } else if (request.getMethod() == "DELETE") {
                if (!handleDeleteRequest(request, server, response)) {
                        logEvent(&server, "DELETE request handling failed");
                }
        }
        return response;
}
