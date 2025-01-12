/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 11:43:45 by pollivie          #+#    #+#             */
/*   Updated: 2025/01/02 11:43:45 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef UTILS_HPP
#define UTILS_HPP

#include "Common.hpp"
#include <sstream>
#include "Server.hpp"
class Server;

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif

template < typename T > std::string to_string(T number) {
        std::ostringstream oss;
        oss << number;
        return oss.str();
}

template < typename T > T to_number(const std::string& str) {
        std::istringstream iss(str);
        T                  number;
        iss >> number;
        if (iss.fail() || !iss.eof()) {
                throw std::runtime_error("Invalid conversion to number.");
        }
        return number;
}

bool             isValidFile(const string& path, i32 flag);
bool             splitContains(const vector< string >& haystack, const string& needle);
bool             splitEndsWith(const vector< string >& haystack, const string& needle);
bool             splitStartsWith(const vector< string >& haystack, const string& needle);
bool             stringContains(const string& haystack, const string& needle);
bool             stringEndsWith(const string& haystack, const string& needle);
bool             stringIsAll(const string& str, i32 (*func)(i32));
bool             stringStartsWith(const string& haystack, const string& needle);
isize            openWriteAll(const string& file_name, const string& buffer, i32 permision, i32 flag);
isize            openReadAll(const string& file_name, string& out);
isize            readAll(i32 fd, string& out_buffer);
isize            recvAll(i32 fd, string& out_buffer);
isize            sendAll(i32 fd, const string& buffer);
isize            splitCount(const vector< string >& haystack, const string& needle);
isize            stringCount(const string& haystack, const string& needle);
string           toAbsolutePath(const string& path);
string           trim(const string& str);
vector< string > split(const string& str, const string& delimiters);
string           normalizePath(string path);
bool             isDirectory(const string& path);
string           generateDirectoryListing(const string& directory_path);
string           determineContentType(const string& file_path);
bool             parseUri(const std::string& uri, string& path, string& file, string& query);
string           normalizeUrl(const string& url);
string           joinPaths(const string& path1, const string& path2);
string           decodeUrl(const string& str);
void             logEvent(Server* server, const string& event);
void             logTimeEvent(const string& event);

#endif //__UTILS_HPP__
