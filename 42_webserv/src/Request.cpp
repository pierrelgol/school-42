/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:42:17 by pollivie          #+#    #+#             */
/*   Updated: 2025/01/10 12:42:17 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Request.hpp"

Request::Request() : _method(""), _uri(""), _version(""), _body(""), _errors(""), _status(0), _headers(), _post_kv(), _files() {
}

Request::Request(const Request &rhs) {
        *this = rhs;
}

Request &Request::operator=(const Request &rhs) {
        if (this != &rhs) {
                _method  = rhs._method;
                _uri     = rhs._uri;
                _version = rhs._version;
                _body    = rhs._body;
                _errors  = rhs._errors;
                _status  = rhs._status;
                _headers = rhs._headers;
                _post_kv = rhs._post_kv;
                _files   = rhs._files;
        }
        return *this;
}

Request::~Request() {
}


bool Request::emitError(i32 code, const string &message) {
        _status = code;
        _errors = message;
        return (false);
}

bool Request::parseClientRequest(const string &raw_request) {
        usize header_end = raw_request.find("\r\n\r\n");

        if (header_end == string::npos) {
                return emitError(400, "Bad Request");
        }

        std::istringstream request_stream(raw_request);
        string             line;
        std::getline(request_stream, line);
        line.erase(line.find_last_not_of("\r\n") + 1);

        std::istringstream line_stream(line);
        if (!(line_stream >> _method >> _uri >> _version)) {
                return emitError(400, "Bad Request");
        }

        if (_method != "GET" && _method != "POST" && _method != "DELETE") {
                return emitError(405, "Method Not Allowed");
        }

        if (_version != "HTTP/1.1" && _version != "HTTP/1.0") {
                return emitError(505, "HTTP Version Not Supported");
        }

        string header = raw_request.substr(0, header_end);
        parseHeaders(header);
        _body = raw_request.substr(header_end + 4);

        // Validate GET method
        if (_method == "GET" && !_body.empty()) {
                return emitError(400, "Bad Request: GET requests must not contain a body");
        }

        // Validate POST method
        if (_method == "POST") {
                if (!containsKey("Content-Type")) {
                        return emitError(400, "Bad Request: Missing Content-Type");
                }

                if (!containsKey("Content-Length") || _headers["Content-Length"].empty()) {
                        return emitError(411, "Length Required");
                }

                try {
                        size_t content_length = std::atoll(_headers["Content-Length"].c_str());
                        if (_body.size() != content_length) {
                                return emitError(400, "Bad Request: Mismatched Content-Length");
                        }
                } catch (std::exception &) {
                        return emitError(400, "Bad Request: Invalid Content-Length");
                }

                if (!parsePostBody()) {
                        return emitError(400, "Bad Request: Invalid Body");
                }
        }

        // Validate DELETE method
        if (_method == "DELETE" && !_body.empty()) {
                return emitError(400, "Bad Request: DELETE requests must not contain a body");
        }

        return true;
}


void Request::parseHeaders(const string &headers) {
        std::istringstream headerStream(headers);
        string             line;
        while (std::getline(headerStream, line) && line != "\r") {
                line.erase(line.find_last_not_of("\r\n") + 1);
                size_t delimiter = line.find(": ");
                if (delimiter != string::npos) {
                        string key    = line.substr(0, delimiter);
                        string value  = line.substr(delimiter + 2);
                        _headers[key] = value;
                }
        }
}

bool Request::parsePostBody() {
        string content_type = getHeader("Content-Type");

        if (content_type.empty()) {
                return false;
        }

        if (content_type == "application/x-www-form-urlencoded") {
                return parsePostBodyUrlEncoded();
        } else if (content_type.find("multipart/form-data") != string::npos) {
                return parsePostBodyMultipartFormData();
        } else {
                return false;
        }
        return true;
}

bool Request::parsePostBodyUrlEncoded() {
        std::istringstream body_stream(_body);
        string             pair;

        while (std::getline(body_stream, pair, '&')) {
                size_t delimiter = pair.find('=');
                if (delimiter != string::npos) {
                        string key    = decodeUrl(pair.substr(0, delimiter));
                        string value  = decodeUrl(pair.substr(delimiter + 1));
                        _post_kv[key] = value;
                } else {
                        return false;
                }
        }
        return true;
}

bool Request::parsePostBodyMultipartFormData() {
        usize boundary_pos = getHeader("Content-Type").find("boundary=");
        if (boundary_pos == string::npos) {
                return false;
        }

        string boundary = "--" + getHeader("Content-Type").substr(boundary_pos + 9);
        usize  start    = _body.find(boundary);

        while (start != string::npos) {
                usize end = _body.find(boundary, start + boundary.size());
                if (end == string::npos) break;

                string part = _body.substr(start + boundary.size(), end - (start + boundary.size()));
                if (!processMultipartData(part)) {
                        return false;
                }
                start = end;
        }
        return true;
}


bool Request::processMultipartData(const string &part) {
        usize header_end = part.find("\r\n\r\n");
        if (header_end == string::npos) return false;

        string headers             = part.substr(0, header_end);
        string body                = part.substr(header_end + 4);

        string content_disposition = extractHeaderValue(headers, "Content-Disposition");
        if (content_disposition.empty()) return false;

        usize name_pos     = content_disposition.find("name=\"");
        usize filename_pos = content_disposition.find("filename=\"");

        if (filename_pos != string::npos) {

                FileData file_data;
                file_data._filename     = extractQuotedValue(content_disposition, "filename=\"");
                file_data._content_type = extractHeaderValue(headers, "Content-Type");

                if (file_data._filename.empty()) return false;

                file_data._content          = body;
                _files[file_data._filename] = file_data;
        } else if (name_pos != string::npos) {

                string name = extractQuotedValue(content_disposition, "name=\"");
                if (name.empty()) return false;

                _post_kv[name] = body;
        } else {
                return false;
        }

        return true;
}



string Request::extractHeaderValue(const string &headers, const string &key) {
        usize key_pos = headers.find(key);
        if (key_pos == string::npos) return "";

        usize value_start = headers.find(": ", key_pos);
        usize value_end   = headers.find("\r\n", value_start);
        if (value_start == string::npos || value_end == string::npos) return "";

        return headers.substr(value_start + 2, value_end - (value_start + 2));
}


string Request::extractQuotedValue(const string &str, const string &key) {
        usize key_pos = str.find(key);
        if (key_pos == string::npos) return "";

        usize start = key_pos + key.size();
        usize end   = str.find("\"", start);
        return (end == string::npos) ? "" : str.substr(start, end - start);
}



string Request::getMethod() const {
        return _method;
}

string Request::getUri() const {
        return _uri;
}

string Request::getVersion() const {
        return _version;
}

string Request::getHeader(const string &key) const {
        if (_headers.find(key) != _headers.end()) {
                return _headers.at(key);
        } else {
                return "";
        }
}

string Request::getBody() const {
        return _body;
}

bool Request::containsKey(const string &key) const {
        if (_headers.find(key) != _headers.end()) {
                return true;
        } else {
                return false;
        }
}

bool Request::containsKeyWithValue(const string &key, const string &value) const {
        if (_headers.find(key) != _headers.end()) {
                return _headers.at(key) == value;
        } else {
                return false;
        }
}

const map< string, string > &Request::getPostKv() const {
        return _post_kv;
}
const map< string, FileData > &Request::getFiles() const {
        return _files;
}

i32 Request::getErrorCode() const {
        return _status;
}

string Request::getErrorMessage() const {
        return _errors;
}

const map< string, string > &Request::getHeaders() const {
        return _headers;
}

usize Request::getBodySize() const {
        return _body.size();
}

void Request::print() const {
        println("Request :");
        println("    method  : " + _method);
        println("    uri     : " + _uri);
        println("    version : " + _version);
        println("    headers : ");
        for (map< string, string >::const_iterator it = _headers.begin(); it != _headers.end(); ++it) {
                println("        " + it->first + ": " + it->second);
        }
        println("    body size: " + to_string(_body.size()));

        println("    post key-value pairs: ");
        for (map< string, string >::const_iterator it = _post_kv.begin(); it != _post_kv.end(); ++it) {
                println("        " + it->first + ": " + it->second);
        }

        println("    files: ");
        for (map< string, FileData >::const_iterator it = _files.begin(); it != _files.end(); ++it) {
                const FileData &file_data = it->second;
                println("        filename     : " + file_data._filename);
                println("        content type : " + file_data._content_type);
                println("        content size : " + to_string(file_data._content.size()));
                println("        content      : " + file_data._content);
        }

        println("    errors  : " + _errors);
        println("    code    : " + to_string(_status));
}
