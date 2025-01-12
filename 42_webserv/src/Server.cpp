/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:41:59 by pollivie          #+#    #+#             */
/*   Updated: 2025/01/10 12:42:00 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"
#include <cerrno>

Server::Server()
    : _address(), _socket(-1), _port(0), _root(""), _server_name("0.0.0.0"), _max_body_size(4096), _error_pages(), _locations(), _async_cgis(),
      _async_responses(), _pending_cgis() {
}

Server::Server(const Server &rhs) {
        *this = rhs;
}

Server &Server::operator=(const Server &rhs) {
        if (this != &rhs) {
                _address         = rhs._address;
                _socket          = rhs._socket;
                _port            = rhs._port;
                _root            = rhs._root;
                _server_name     = rhs._server_name;
                _max_body_size   = rhs._max_body_size;
                _error_pages     = rhs._error_pages;
                _locations       = rhs._locations;
                _async_cgis      = rhs._async_cgis;
                _async_responses = rhs._async_responses;
                _pending_cgis    = rhs._pending_cgis;
        }
        return *this;
}

Server::~Server() {
}

string Server::getServerPrettyName() const {
        return _server_name + ":" + to_string(_port);
}

struct sockaddr_in Server::getAddress() const {
        return _address;
}

i32 Server::getSocket() const {
        return _socket;
}

i32 Server::getPort() const {
        return _port;
}

string Server::getRoot() const {
        return _root;
}

string Server::getIndex() const {
        return _index;
}

string Server::getServerName() const {
        return _server_name;
}
usize Server::getMaxBodySize() const {
        return _max_body_size;
}

const map< i32, string > &Server::getErrorPages() const {
        return _error_pages;
}

const vector< Location > &Server::getLocations() const {
        return _locations;
}

void Server::setAddress(struct sockaddr_in &address) {
        _address = address;
}

void Server::setSocket(i32 socket) {
        _socket = socket;
}

void Server::setPort(i32 port) {
        _port = port;
}

void Server::setRoot(const string &root) {
        _root = root;
}

void Server::setIndex(const string &index) {
        _index = index;
}

void Server::setServerName(const string &server_name) {
        _server_name = server_name;
}

void Server::setMaxBodySize(usize max_body_size) {
        _max_body_size = max_body_size;
}

void Server::addErrorPage(const pair< i32, string > &error_page) {
        _error_pages.insert(error_page);
}

void Server::addLocation(const Location &location) {
        _locations.push_back(location);
}

string Server::getErrorPage(i32 error_code) const {
        if (_error_pages.find(error_code) != _error_pages.end()) {
                return _error_pages.at(error_code);
        } else {
                return "";
        }
}

bool Server::init() {
        _socket = socket(AF_INET, SOCK_STREAM, 0);
        if (_socket == -1) {
                throw WebservError::NetworkException(": failed to open socket : " + string(strerror(errno)));
        }

        i32 optval = 1;
        if (setsockopt(_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &optval, sizeof(optval)) == -1) {
                close(_socket);
                throw WebservError::NetworkException(": failed to configure socket : " + string(strerror(errno)));
        }

        _address.sin_family = AF_INET;
        _address.sin_port   = htons(_port);
        if (inet_pton(AF_INET, _server_name.c_str(), &_address.sin_addr.s_addr) == -1) {
                throw WebservError::NetworkException("_address provided in in an invalid format : " + string(strerror(errno)));
        }

        if (fcntl(_socket, F_SETFD, O_NONBLOCK) == -1) {
                close(_socket);
                throw WebservError::NetworkException("failed to set socket to O_NONBLOCK : " + string(strerror(errno)));
        }

        if (bind(_socket, (struct sockaddr *)&_address, sizeof(_address)) == -1) {
                close(_socket);
                throw WebservError::NetworkException(string(__FUNCTION__) + ": failed to bind socket : " + string(strerror(errno)));
        }

        if (listen(_socket, SOMAXCONN) == -1) {
                close(_socket);
                throw WebservError::NetworkException(string(__FUNCTION__) + ": failed to listen with socket : " + string(strerror(errno)));
        }
        return true;
}


void Server::deinit() {
        if (_socket != -1) {
                close(_socket);
                _socket = -1;
        }

        for (usize i = 0; i < _pending_cgis.size(); i++) {
                delete _pending_cgis[i];
        }
}


// bool Server::getMatchingLocation(const string &uri, Location &out_location) {
//         Location *best_match           = NULL;
//         string    normalized_uri       = normalizeUrl(uri);
//         usize     longest_match_length = 0;
//         for (usize i = 0; i < _locations.size(); ++i) {
//                 const Location &location = _locations[i];
//                 if (location.doesMatchUrl(normalized_uri)) {
//                         usize match_length = location.getPath().length();

//                         if (match_length > longest_match_length) {
//                                 best_match           = &_locations[i];
//                                 longest_match_length = match_length;
//                         }
//                 }
//         }

//         if (best_match) {
//                 out_location = *best_match;
//                 return true;
//         }

//         return false;
// }

bool Server::getMatchingLocation(const string &uri, Location &out_location) {
        Location *best_match           = NULL;
        string    normalized_uri       = normalizeUrl(uri);
        usize     longest_match_length = 0;

        for (usize i = 0; i < _locations.size(); ++i) {
                const Location &location = _locations[i];
                if (location.doesMatchUrl(normalized_uri)) {
                        usize match_length = location.getPath().length();

                        // If the location is a CGI (doesn't end with '/'), prefer exact matches
                        if (!location.getPath().empty() && location.getPath()[location.getPath().size() - 1] != '/') {
                                if (normalized_uri == location.getPath()) {
                                        best_match = &_locations[i];
                                        break; // Exact match for CGI location, no need to check further
                                }
                        } else if (match_length > longest_match_length) {
                                // Regular longest match logic
                                best_match           = &_locations[i];
                                longest_match_length = match_length;
                        }
                }
        }

        if (best_match) {
                out_location = *best_match;
                return true;
        }

        return false;
}

bool Server::addAsyncCgi(Request &request, const string &method, i32 client, Response &response) {
        Cgi *cgi = new Cgi(method, client, response.getCgiPath(), response.getCgiArgs(), request);
        if (!cgi) {
                response.emitError(500, "Error 500 : Internal Server Error", *this);
                return false;
        }

        if (!cgi->start(request)) {
                println("HERE");
                delete cgi;
                response.emitError(500, "Error 500 : Internal Server Error", *this);
                return false;
        }
        _pending_cgis.insert(std::make_pair(cgi->getReadFd(), cgi));
        _async_cgis.insert(std::make_pair(client, cgi));
        _async_responses.insert(std::make_pair(client, response));
        return true;
}

void Server::removeClient(i32 client) {
        LOG_STACK_TRACE();
        logEvent(this, "Removing client FD: " + to_string(client));

        Response response;
        Cgi     *cgi = getAsyncCgis(client);

        // Handle CGI cleanup if associated
        if (!cgi) {
                logEvent(this, "No associated CGI found for client FD: " + to_string(client));
                if (!getAsyncResponses(client).isAsync()) {
                        response.emitError(500, "Error 500: Internal Server Error", *this);
                        sendAll(client, response.getResponse());
                }
                return;
        }

        // Remove client from CGI and responses map
        if (_async_cgis.find(client) != _async_cgis.end()) {
                _async_cgis.erase(client);
                logEvent(this, "Removed client FD from async CGI map: " + to_string(client));
        }

        if (_async_responses.find(client) != _async_responses.end()) {
                _async_responses.erase(client);
                logEvent(this, "Removed client FD from async responses map: " + to_string(client));
        }

        // Remove CGI FD from pending list
        if (_pending_cgis.find(cgi->getReadFd()) != _pending_cgis.end()) {
                _pending_cgis.erase(cgi->getReadFd());
                logEvent(this, "Removed CGI FD from pending list: " + to_string(cgi->getReadFd()));
        }

        // Cleanup and delete the CGI instance
        cgi->cleanup();
        delete cgi;
        logEvent(this, "Cleaned up and deleted CGI instance for client FD: " + to_string(client));
}

const map< i32, Cgi * > &Server::getAsyncCgis() const {
        return _async_cgis;
}

Cgi *Server::getAsyncCgis(i32 client) const {
        if (_async_cgis.find(client) != _async_cgis.end()) {
                return _async_cgis.at(client);
        }
        return NULL;
}

const map< i32, Response > &Server::getAsyncResponses() const {
        return _async_responses;
}

Response Server::getAsyncResponses(i32 client) const {
        if (_async_responses.find(client) != _async_responses.end()) {
                return _async_responses.at(client);
        }
        return Response();
}

const map< i32, Cgi * > &Server::getPendingCgis() const {
        return _pending_cgis;
}

Cgi *Server::getCgiByCgiFd(i32 cgi_fd) const {
        if (_pending_cgis.find(cgi_fd) != _pending_cgis.end()) {
                return _pending_cgis.at(cgi_fd);
        }
        return NULL;
}

std::ostream &operator<<(std::ostream &os, const Server &self) {
        os << "    name          : " << self.getServerName() << ":" << self.getPort() << std::endl;
        os << "    socket        : " << self.getSocket() << std::endl;
        os << "    root          : " << self.getRoot() << std::endl;
        os << "    max_body_size : " << self.getMaxBodySize() << std::endl;
        os << "    error_pages   :" << std::endl;
        const map< i32, string > &error_pages = self.getErrorPages();
        for (map< i32, string >::const_iterator it = error_pages.begin(); it != error_pages.end(); ++it) {
                os << "    [" << it->first << "] --> " << it->second << std::endl;
        }

        os << std::endl;
        const vector< Location > &locations = self.getLocations();
        for (vector< Location >::const_iterator it = locations.begin(); it != locations.end(); ++it) {
                os << "    locations:" << std::endl;
                os << *it << std::endl;
        }

        os << std::endl;
        return os;
}
