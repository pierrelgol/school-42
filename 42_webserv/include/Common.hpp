/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Webserv.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 10:54:56 by pollivie          #+#    #+#             */
/*   Updated: 2024/12/28 10:54:57 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef COMMON_HPP
#define COMMON_HPP

#include <vector>
#include <string>
#include <map>
#include <cassert>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <stdio.h>
#include <set>
#include <queue>
#include <errno.h>
#include <string.h>

typedef char              i8;
typedef short             i16;
typedef int               i32;
typedef long int          i64;
typedef long int          isize;
typedef unsigned char     u8;
typedef unsigned short    u16;
typedef unsigned int      u32;
typedef unsigned long int u64;
typedef unsigned long int usize;

using std::map;
using std::pair;
using std::queue;
using std::set;
using std::string;
using std::stringstream;
using std::vector;

#define println(x)  std::cerr << x << std::endl
#define eprintln(x) std::cerr << x << std::endl
#define Error()     string(strerror(errno))

typedef string::iterator                      StringIter;
typedef string::const_iterator                StringConstIter;
typedef vector< string >::iterator            VecStringIter;
typedef vector< string >::const_iterator      VecStringConstIter;
typedef map< u16, string >::iterator          MapErrorPageIter;
typedef map< u16, string >::const_iterator    MapErrorPageConstIter;
typedef map< string, string >::iterator       MapStringStringIter;
typedef map< string, string >::const_iterator MapStringStringConstIter;

class WebservError {
      public:
        class BaseException : public std::exception {
              protected:
                std::string _msg;

              public:
                BaseException(const std::string& msg) : _msg(msg) {
                }
                virtual ~BaseException() throw() {
                }
                virtual const char* what() const throw() {
                        return _msg.c_str();
                }
        };

        class FileException : public BaseException {
              public:
                FileException(const std::string& msg) : BaseException("File Error: " + msg) {
                }
        };

        class NetworkException : public BaseException {
              public:
                NetworkException(const std::string& msg) : BaseException("Network Error: " + msg) {
                }
        };

        class ConfigurationException : public BaseException {
              public:
                ConfigurationException(const std::string& msg) : BaseException("Config Error: " + msg) {
                }
        };

        class UnexpectedException : public BaseException {
              public:
                UnexpectedException(const std::string& msg) : BaseException("Unexpected Error: " + msg) {
                }
        };
};


#define COLOR_RESET  "\033[0m"
#define COLOR_GREEN  "\033[32m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_CYAN   "\033[36m"

#define LOG_STACK_TRACE()                                                                                                                                      \
        do {                                                                                                                                                   \
                fprintf(stderr,                                                                                                                                \
                        COLOR_GREEN "[LOG]" COLOR_RESET COLOR_CYAN ": %s" COLOR_RESET ", " COLOR_YELLOW "File: %s" COLOR_RESET ", " COLOR_YELLOW               \
                                    "Line: %d" COLOR_RESET "\n",                                                                                               \
                        __PRETTY_FUNCTION__,                                                                                                                   \
                        __FILE__,                                                                                                                              \
                        __LINE__);                                                                                                                             \
        } while (0)

#define LOG_INFO(msg) std::cerr << __FUNCTION__ << " (" << __FILE__ << ":" << __LINE__ << ") " << msg << std::endl;

struct FileData {
        string _filename;
        string _content_type;
        string _content;

        FileData() : _filename(""), _content_type(""), _content("") {
        }

        FileData(const FileData& rhs) {
                *this = rhs;
        }

        FileData& operator=(const FileData& rhs) {
                if (this != &rhs) {
                        _filename     = rhs._filename;
                        _content_type = rhs._content_type;
                        _content      = rhs._content;
                }
                return *this;
        }

        ~FileData() {
        }
};


#endif //__WEBSERV_HPP__
