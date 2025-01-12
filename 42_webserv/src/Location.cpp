/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Location.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:42:04 by pollivie          #+#    #+#             */
/*   Updated: 2025/01/10 12:42:06 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Location.hpp"
#include <queue>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include "Utils.hpp"

Location::Location() : _autoindex(false), _path(""), _root(""), _index(""), _cgi_path(""), _methods() {
}

Location::Location(const Location &rhs) {
        *this = rhs;
}

Location &Location::operator=(const Location &rhs) {
        if (this != &rhs) {
                _autoindex = rhs._autoindex;
                _path      = rhs._path;
                _root      = rhs._root;
                _index     = rhs._index;
                _cgi_path  = rhs._cgi_path;
                _methods   = rhs._methods;
        }
        return *this;
}

Location::~Location() {
}

string Location::getFullCgiPath() const {
        return _cgi_path;
}

bool Location::getAutoIndex() const {
        return _autoindex;
}

string Location::getPath() const {
        return _path;
}

string Location::getRoot() const {
        return _root;
}

string Location::getIndex() const {
        return _index;
}

string Location::getCgiPath() const {
        return _cgi_path;
}

const set< string > &Location::getMethods() const {
        return _methods;
}

void Location::setAutoIndex(bool autoindex) {
        _autoindex = autoindex;
}

void Location::setPath(const string &path) {
        _path = path;
}

void Location::setRoot(const string &root) {
        _root = root;
}

void Location::setIndex(const string &index) {
        _index = index;
}

void Location::setCgiPath(const string &cgi_path) {
        _cgi_path = cgi_path;
}

void Location::addMethods(const set< string > &methods) {
        _methods = methods;
}


string Location::getFullPath() const {
        string path = _root + _path;
        return normalizePath(path);
}


string Location::getFullIndexPath() const {
        string path = _root + _path + _index;
        return normalizePath(path);
}


bool Location::locationContainsFile(const string &file_path) const {

        string directory_path = file_path.substr(0, file_path.find_last_of("/"));
        string target_file    = file_path.substr(file_path.find_last_of("/") + 1);

        if (target_file == getIndex()) {
                return true;
        }

        if (directory_path.empty() || target_file.empty()) {
                return false;
        }


        queue< string > directories;
        directories.push(directory_path);

        while (!directories.empty()) {
                string current_dir = directories.front();
                directories.pop();

                DIR *dir = opendir(current_dir.c_str());
                if (!dir) {
                        continue;
                }

                struct dirent *entry;
                while ((entry = readdir(dir)) != NULL) {
                        string entry_name = entry->d_name;


                        if (entry_name == "." || entry_name == "..") {
                                continue;
                        }


                        string      entry_path = current_dir + "/" + entry_name;
                        struct stat entry_stat;
                        if (stat(entry_path.c_str(), &entry_stat) == -1) {
                                continue;
                        }

                        if (S_ISDIR(entry_stat.st_mode)) {
                                directories.push(entry_path);
                        } else if (S_ISREG(entry_stat.st_mode) && entry_name == target_file) {
                                closedir(dir);
                                return true;
                        }
                }

                closedir(dir);
        }

        return false;
}


bool Location::isMethodAllowed(const string &method) const {
        if (_methods.empty() and (method == "GET" or method == "POST" or method == "DELETE")) {
                return true;
        } else if (_methods.find(method) != _methods.end()) {
                return true;
        }
        return false;
}


bool Location::isAutoIndexEnabled() const {
        return _autoindex;
}


bool Location::doesMatchUrl(const string &url) const {
        string normalized_url  = normalizeUrl(url);
        string normalized_path = normalizeUrl(_path);

        if (!normalized_path.empty() && normalized_path[normalized_path.size() - 1] == '/') {
                if (normalized_url.find(normalized_path) != 0) {
                        return false;
                }

                usize path_len = normalized_path.length();
                if (normalized_url.length() > path_len && normalized_url[path_len] != '/') {
                        return false;
                }

                return true;
        }

        return normalized_url == normalized_path;
}


std::ostream &operator<<(std::ostream &os, const Location &self) {
        os << "        autoindex : " << (self.getAutoIndex() ? "True" : "False") << std::endl;
        os << "        root      : " << self.getRoot() << std::endl;
        os << "        index     : " << self.getIndex() << std::endl;
        os << "        cgi_path  : " << self.getCgiPath() << std::endl;
        os << "        methods   : ";
        const std::set< std::string > &methods = self.getMethods();
        os << "[";
        for (std::set< std::string >::const_iterator it = methods.begin(); it != methods.end(); ++it) {
                if (it != methods.begin()) {
                        os << ", ";
                }
                os << *it;
        }
        os << "]" << std::endl;
        return os;
}
