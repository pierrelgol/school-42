/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cgi.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:22:32 by pollivie          #+#    #+#             */
/*   Updated: 2025/01/12 14:22:32 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CGI_HPP
#define CGI_HPP

class Cgi;
#include "Common.hpp"
#include "Utils.hpp"

#include "Request.hpp"
class Request;

class Cgi {
      private:
        i32     _client;
        i32     _pid;
        i32     _fd;
        time_t  _since;
        string  _path;
        string  _args;
        string  _method;
        Request _request;

        Cgi();
        Cgi(const Cgi &rhs);
        Cgi &operator=(const Cgi &rhs);

      public:
        Cgi(const string &method, i32 client, const string &path, const string &args, Request &request);
        ~Cgi();

        bool   hasTimeout(time_t now, time_t timeout) const;
        i32    getReadFd() const;
        i32    getClientFd() const;

        bool   start(Request &request);
        char **build_env(Request &request);
        void   cleanup();
};

#endif
