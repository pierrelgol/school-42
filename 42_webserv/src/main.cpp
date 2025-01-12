/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:09:56 by pollivie          #+#    #+#             */
/*   Updated: 2025/01/10 12:09:56 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Common.hpp"
#include "Utils.hpp"
#include "Server.hpp"
#include "Location.hpp"
#include "Request.hpp"
#include "Response.hpp"
#include "Parser.hpp"
#include <cerrno>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <signal.h>
#include "Webserv.hpp"

i32 main(i32 argc, i8 **argv) {

        if (argc != 2 or argv[1][0] == '\0') {
                eprintln("Error missing file configuration!");
                return (1);
        }

        Parser parser;

        try {
                parser.parseConfigFile(argv[1]);
                println(parser);
                Webserv webserv(parser.getServers());
                webserv.startWebserver();

        } catch (const std::exception &e) {
                eprintln(e.what());
                return (1);
        }

        return (0);
}
