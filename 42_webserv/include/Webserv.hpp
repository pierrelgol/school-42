/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Webserv.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 10:52:01 by pollivie          #+#    #+#             */
/*   Updated: 2025/01/11 22:51:25 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WEBSERV_HPP
#define WEBSERV_HPP

#include "Common.hpp"
#include "Utils.hpp"
#include "Server.hpp"
class Server;
#include "Location.hpp"
class Location;
#include "Request.hpp"
class Request;
#include "Response.hpp"
class Response;

#include <sys/epoll.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <signal.h>
#include <cerrno>

#ifndef SERVER_MAX_EVENTS
#define SERVER_MAX_EVENTS 64
#endif

#ifndef SERVER_MAX_TIMEOUT
#define SERVER_MAX_TIMEOUT 100
#endif

class Webserv {
      private:
        i32                  _epfd;
        i32                  _nfds;
        struct epoll_event   _events[SERVER_MAX_EVENTS];
        struct epoll_event   _ev;
        vector< Server >     _servers;
        vector< i32 >        _servers_fd;
        vector< i32 >        _clients_fd;
        vector< i32 >        _cgis_fd;
        map< i32, Server * > _clients_handler;
        map< i32, Server * > _cgi_handler;

      public:
        Webserv();
        Webserv(const vector< Server > &servers);
        Webserv(const Webserv &rhs);
        Webserv &operator=(const Webserv &rhs);
        ~Webserv();

        void     setupEpollInstance();
        void     setupSignalHandling();
        void     setupServers();
        void     startWebserver();
        void     closeWebserver();

        void     appendClient(i32 client, Server *server);
        void     removeClient(i32 client);

        bool     asyncRequestPending(i32 client);
        bool     handleClientRequest(i32 client_fd, Server &server);
        Response serverRespond(Request &request, Server &handler);

        Server  *getServer(i32 fd);
        bool     isServer(i32 fd);
        bool     isClient(i32 fd);
        bool     isCgi(i32 fd);

        bool     handleGetRequest(Request &request, Server &handler, Response &response);
        bool     handlePostRequest(Request &request, Server &handler, Response &response);
        bool     handleDeleteRequest(Request &request, Server &handler, Response &response);
        bool     handleGetGciRequest(Request &request, Server &server, Response &response, string cgi_path, string query_uri);
};

#endif // SERVERMANAGER_HPP
