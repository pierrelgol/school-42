/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:37:35 by pollivie          #+#    #+#             */
/*   Updated: 2025/01/10 12:37:35 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PARSER_HPP
#define PARSER_HPP

#include "Common.hpp"
#include "Utils.hpp"

#include "Server.hpp"
class Server;

#include "Location.hpp"
class Location;


class Parser {
      private:
        vector< Server > _servers;
        set< i32 >       _listening_ports;
        set< string >    _servers_name;

      public:
        Parser();
        Parser(const Parser &rhs);
        Parser &operator=(const Parser &rhs);
        ~Parser();

        const vector< Server > &getServers() const;
        const set< i32 >       &getListeningPorts() const;
        const set< string >    &getServersName() const;

        void                    parseConfigFile(const string &config_file);
        Server                  parseServerBlock(std::ifstream &file, vector< string > &line_split);
        Location                parseLocationBlock(std::ifstream &file, vector< string > &line_split);

        i32                     parseServerPort(const vector< string > &line_split);
        string                  parseRoot(const vector< string > &line_split);
        string                  parseIndex(const vector< string > &line_split);
        string                  parseServerName(const vector< string > &line_split);
        string                  parseLocationPath(const vector< string > &line_split);
        usize                   parseMaxBodySize(const vector< string > &line_split);
        pair< i32, string >     parseErrorPage(const vector< string > &line_split);
        bool                    parseAutoIndex(const vector< string > &line_split);
        string                  parseCgiPath(const vector< string > &line_split);
        set< string >           parseMethods(const vector< string > &line_split);

        bool                    isValidPort(const string &port);
        bool                    isValidServerName(const string &server_name);
        bool                    isValidErrorPage(const vector< string > &line_split);
        bool                    isListeningPortUnique(i32 port);
        bool                    isServerNameUnique(const string &server_name);
        void                    addPortToSet(i32 port);
        void                    addServerNameToSet(const string &server_name);
};

std::ostream &operator<<(std::ostream &os, const Parser &self);

#endif // PARSER_HPP
