/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:40:00 by pollivie          #+#    #+#             */
/*   Updated: 2025/01/10 12:40:00 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef REQUEST_HPP
#define REQUEST_HPP

#include "Common.hpp"

class Request {
      private:
        string                  _method;
        string                  _uri;
        string                  _version;
        string                  _body;
        string                  _errors;
        i32                     _status;
        map< string, string >   _headers;
        map< string, string >   _post_kv;
        map< string, FileData > _files;

        bool                    emitError(i32 code, const string &message);

      public:
        Request();
        Request(const Request &rhs);
        Request &operator=(const Request &rhs);
        ~Request();

        bool                           parseClientRequest(const string &raw_request);
        void                           parseHeaders(const string &headers);
        bool                           parsePostBody();
        bool                           parsePostBodyUrlEncoded();
        bool                           parsePostBodyMultipartFormData();
        bool                           processMultipartData(const string &part);
        string                         extractHeaderValue(const string &headers, const string &key);
        string                         extractQuotedValue(const string &str, const string &key);

        string                         getMethod() const;
        string                         getUri() const;
        string                         getVersion() const;
        string                         getHeader(const string &key) const;
        string                         getBody() const;
        string                         getPostKey(const string &key) const;
        FileData                       getFileData(const string &key) const;
        bool                           containsKey(const string &key) const;
        bool                           containsKeyWithValue(const string &key, const string &value) const;
        i32                            getErrorCode() const;
        string                         getErrorMessage() const;
        const map< string, string >   &getHeaders() const;
        const map< string, string >   &getPostKv() const;
        const map< string, FileData > &getFiles() const;
        usize                          getBodySize() const;

        void                           print() const;
};

#include "Utils.hpp"

#endif // REQUEST_HPP
