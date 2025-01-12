/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Response.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:42:12 by pollivie          #+#    #+#             */
/*   Updated: 2025/01/10 12:42:12 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Response.hpp"

Response::Response() : _info(), _header(), _body(""), _error(false), _async_gci(false), _cgi_path(""), _cgi_args("") {
        _info["Version"]          = "HTTP/1.1";
        _info["Status"]           = "200";
        _info["Reason"]           = "OK";
        _header["Content-Type"]   = "text/html";
        _header["Content-Length"] = "0";
}

Response::Response(const Response &rhs) {
        *this = rhs;
}

Response &Response::operator=(const Response &rhs) {
        if (this != &rhs) {
                _info      = rhs._info;
                _header    = rhs._header;
                _body      = rhs._body;
                _error     = rhs._error;
                _async_gci = rhs._async_gci;
                _cgi_path  = rhs._cgi_path;
                _cgi_args  = rhs._cgi_args;
        }
        return *this;
}

Response::~Response() {
}

void Response::setInfo(const string &key, const string &value) {
        _info[key] = value;
}

void Response::setHeader(const string &key, const string &value) {
        _header[key] = value;
}

void Response::setBody(const string &body) {
        _body                     = body;
        _header["Content-Length"] = to_string(_body.size());
}

string Response::emitError(i32 code, const string &msg, Server &server) {
        logEvent(&server, "Emitting error response: Code " + to_string(code) + ", Message: " + msg);

        string error_page = server.getErrorPage(code);
        logEvent(&server, "Error page path for code " + to_string(code) + ": '" + error_page + "'.");

        string response;

        _info["Version"]        = "HTTP/1.1";
        _info["Status"]         = to_string(code);
        _info["Reason"]         = msg;
        _header["Content-Type"] = "text/html";

        if (error_page.empty()) {
                logEvent(&server, "No custom error page defined for code " + to_string(code) + ". Generating default error body.");
                _body += "<html><body><h1>" + msg + "</h1></body></html>";
                _header["Content-Length"] = to_string(_body.size());
        } else {
                if (!server.getRoot().empty()) {
                        error_page = server.getRoot() + error_page;
                        logEvent(&server, "Resolved error page with server root: '" + error_page + "'.");
                        error_page = toAbsolutePath(normalizePath(error_page));
                        logEvent(&server, "Normalized error page path: '" + error_page + "'.");
                }

                isize rbytes = openReadAll(error_page, _body);
                if (rbytes <= 0 || _body.empty()) {
                        logEvent(&server, "Failed to read error page: '" + error_page + "'. Emitting 500 Internal Server Error.");
                        emitError(500, "Error 500 : Internal Server Error", server);
                        return response;
                }
                logEvent(&server, "Successfully read error page: '" + error_page + "' (" + to_string(rbytes) + " bytes).");
        }

        _header["Content-Length"] = to_string(_body.size());
        logEvent(&server, "Final error response prepared: Code " + to_string(code) + ", Content-Length: " + _header["Content-Length"] + ".");
        return response;
}


string Response::getInfo(const string &key) const {
        if (_info.find(key) == _info.end()) {
                return "";
        } else {
                return _info.at(key);
        }
}

string Response::getHeader(const string &key) const {
        if (_header.find(key) == _header.end()) {
                return "";
        } else {
                return _header.at(key);
        }
}

string Response::getBody() const {
        return _body;
}

void Response::setAsyncCgi(const string &cgi_path, const string &args) {
        _async_gci = true;
        _cgi_path  = cgi_path;
        _cgi_args  = args;
}

string Response::getCgiPath() const {
        return _cgi_path;
}

string Response::getCgiArgs() const {
        return _cgi_args;
}

bool Response::isAsync() const {
        return _async_gci;
}

string Response::getResponse() const {
        string response = _info.at("Version") + " " + _info.at("Status") + " " + _info.at("Reason") + "\r\n";
        for (map< string, string >::const_iterator it = _header.begin(); it != _header.end(); it++) {
                response += it->first + ": " + it->second + "\r\n";
        }
        response += "\r\n" + _body;
        return response;
}

bool Response::isSucessful() const {
        i32 status = to_number< i32 >(getInfo("Status"));
        if (status >= 400) {
                return false;
        } else {
                return true;
        }
}
