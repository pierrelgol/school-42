/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Location.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:38:13 by pollivie          #+#    #+#             */
/*   Updated: 2025/01/10 12:38:14 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef LOCATION_HPP
#define LOCATION_HPP

class Location;
#include "Common.hpp"
#include "Utils.hpp"
#include "Server.hpp"
class Server;

class Location {
      private:
        bool          _autoindex;
        string        _path;
        string        _root;
        string        _index;
        string        _cgi_path;
        set< string > _methods;

      public:
        Location();
        Location(const Location &rhs);
        Location &operator=(const Location &rhs);
        ~Location();

        bool                 getAutoIndex() const;
        string               getPath() const;
        string               getRoot() const;
        string               getIndex() const;
        string               getCgiPath() const;
        const set< string > &getMethods() const;

        void                 setAutoIndex(bool autoindex);
        void                 setPath(const string &path);
        void                 setRoot(const string &root);
        void                 setIndex(const string &index);
        void                 setCgiPath(const string &cgi_path);
        void                 addMethods(const set< string > &methods);

        string               getFullCgiPath() const;
        // returns _root + _path;
        string getFullPath() const;

        // returns _root + _path + _index;
        string getFullIndexPath() const;

        // returns true if access(file_path, F_OK) is valid;
        bool locationContainsFile(const string &file_path) const;

        // returns true is 'method' is in the set of allowed methods;
        bool isMethodAllowed(const string &method) const;

        // returns true if location has autoindex capabilities on;
        bool isAutoIndexEnabled() const;

        // returns true if the Location contains a subset of url;
        bool doesMatchUrl(const string &url) const;
};

std::ostream &operator<<(std::ostream &os, const Location &self);


#endif // LOCATION_HPP
