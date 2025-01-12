/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Response.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:39:52 by pollivie          #+#    #+#             */
/*   Updated: 2025/01/10 12:39:52 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef RESPONSE_HPP
#define RESPONSE_HPP

class Response;
#include "Common.hpp"
#include "Utils.hpp"

#include "Cgi.hpp"
class Cgi;

#include "Server.hpp"
class Server;


class Response {
      private:
        map< string, string > _info;
        map< string, string > _header;
        string                _body;
        bool                  _error;
        bool                  _async_gci;
        string                _cgi_path;
        string                _cgi_args;

      public:
        Response();
        Response(const Response &rhs);
        Response &operator=(const Response &rhs);
        ~Response();

        void   setInfo(const string &key, const string &value);
        void   setHeader(const string &key, const string &value);
        void   setBody(const string &body);
        string emitError(i32 code, const string &msg, Server &server);

        string getInfo(const string &key) const;
        string getHeader(const string &key) const;
        string getBody() const;
        string getResponse() const;
        string getCgiPath() const;
        string getCgiArgs() const;

        bool   isAsync() const;
        bool   isSucessful() const;

        void   setAsyncCgi(const string &cgi_path, const string &args);
};

#endif // RESPONSE_HPP
