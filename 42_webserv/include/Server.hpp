/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:37:46 by pollivie          #+#    #+#             */
/*   Updated: 2025/01/10 12:37:47 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SERVER_HPP
#define SERVER_HPP

class Server;
#include "Common.hpp"
#include "Utils.hpp"
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <fcntl.h>

#include "Cgi.hpp"
class Cgi;

#include "Request.hpp"
class Request;

#include "Response.hpp"
class Response;

#include "Location.hpp"
class Location;

class Server {
      private:
        struct sockaddr_in   _address;
        i32                  _socket;
        i32                  _port;
        string               _root;
        string               _index;
        string               _server_name;
        usize                _max_body_size;
        map< i32, string >   _error_pages;
        vector< Location >   _locations;
        map< i32, Cgi * >    _async_cgis;
        map< i32, Response > _async_responses;
        map< i32, Cgi * >    _pending_cgis;

      public:
        Server();
        Server(const Server &rhs);
        Server &operator=(const Server &rhs);
        ~Server();

        struct sockaddr_in          getAddress() const;
        i32                         getSocket() const;
        i32                         getPort() const;
        string                      getRoot() const;
        string                      getIndex() const;
        string                      getServerName() const;
        usize                       getMaxBodySize() const;
        const map< i32, string >   &getErrorPages() const;
        string                      getErrorPage(i32 error_code) const;

        const map< i32, Cgi * >    &getAsyncCgis() const;
        Cgi                        *getAsyncCgis(i32 client) const;

        const map< i32, Cgi * >    &getPendingCgis() const;
        Cgi                        *getCgiByCgiFd(i32 cgi_fd) const;

        const map< i32, Response > &getAsyncResponses() const;
        Response                    getAsyncResponses(i32 client) const;


        const vector< Location >   &getLocations() const;
        string                      getServerPrettyName() const;
        bool                        getMatchingLocation(const string &uri, Location &out_location);

        void                        setAddress(struct sockaddr_in &address);
        void                        setSocket(i32 socket);
        void                        setPort(i32 port);
        void                        setRoot(const string &root);
        void                        setIndex(const string &index);
        void                        setServerName(const string &server_name);
        void                        setMaxBodySize(usize max_body_size);
        void                        addErrorPage(const pair< i32, string > &error_page);
        void                        addLocation(const Location &location);
        bool                        addAsyncCgi(Request &request, const string &method, i32 client, Response &response);
        void                        removeClient(i32 client);

        // open a non-blocking socket for _port/_address.
        bool init();

        // closes the open socket.
        void deinit();
};

std::ostream &operator<<(std::ostream &os, const Server &self);

#endif // SERVER_HPP
