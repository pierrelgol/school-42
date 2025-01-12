/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:41:50 by pollivie          #+#    #+#             */
/*   Updated: 2025/01/10 12:41:51 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"
#include <fstream>

Parser::Parser() : _servers(), _listening_ports(), _servers_name() {
}

Parser::Parser(const Parser &rhs) : _servers(), _listening_ports(), _servers_name() {
        *this = rhs;
}

Parser &Parser::operator=(const Parser &rhs) {
        if (this != &rhs) {
                _servers         = rhs._servers;
                _listening_ports = rhs._listening_ports;
                _servers_name    = rhs._servers_name;
        }
        return *this;
}

Parser::~Parser() {
}

const vector< Server > &Parser::getServers() const {
        return _servers;
}

const set< i32 > &Parser::getListeningPorts() const {
        return _listening_ports;
}

const set< string > &Parser::getServersName() const {
        return _servers_name;
}

void Parser::parseConfigFile(const string &config_file) {
        std::ifstream file(config_file.c_str());

        if (!file.is_open()) {
                throw WebservError::FileException("webserv failed to open : " + config_file);
        }

        string line;
        while (std::getline(file, line)) {
                if (line.empty()) {
                        continue;
                }

                vector< string > line_split = split(trim(line), " ;\r\t");
                if (line_split.empty()) {
                        continue;
                }

                if (line_split.size() == 2 and line_split[0] == "server" and line_split[1] == "{") {
                        _servers.push_back(parseServerBlock(file, line_split));
                } else {
                        file.close();
                        throw WebservError::ConfigurationException("unexpected token in line : '" + line + "'");
                }
        }
}

Server Parser::parseServerBlock(std::ifstream &file, vector< string > &line_split) {
        Server server;

        string line;
        while (std::getline(file, line)) {
                if (line.empty()) {
                        continue;
                }

                line_split = split(trim(line), " ;\r\t");
                if (line_split.empty()) {
                        continue;
                }

                if (line_split[0] == "listen") {
                        server.setPort(parseServerPort(line_split));
                } else if (line_split[0] == "server_name") {
                        server.setServerName(parseServerName(line_split));
                } else if (line_split[0] == "root") {
                        server.setRoot(parseRoot(line_split));
                } else if (line_split[0] == "index") {
                        server.setIndex(parseIndex(line_split));
                } else if (line_split[0] == "max_body_size") {
                        server.setMaxBodySize(parseMaxBodySize(line_split));
                } else if (line_split[0] == "error_page") {
                        server.addErrorPage(parseErrorPage(line_split));
                } else if (line_split[0] == "location" and line_split.size() == 3 and line_split[2] == "{") {
                        server.addLocation(parseLocationBlock(file, line_split));
                } else if (line_split[0] == "}" and line_split.size() == 1) {
                        break;
                } else {
                        file.close();
                        throw WebservError::ConfigurationException("unexpected token in line : '" + line + "'");
                }
        }
        return server;
}

Location Parser::parseLocationBlock(std::ifstream &file, vector< string > &line_split) {
        Location location;

        if (line_split.size() == 3) {
                location.setPath(parseLocationPath(line_split));
        }

        string line;
        while (std::getline(file, line)) {
                if (line.empty()) {
                        continue;
                }

                line_split = split(trim(line), " ;\r\t");
                if (line_split.empty()) {
                        continue;
                }

                if (line_split[0] == "root") {
                        location.setRoot(parseRoot(line_split));
                } else if (line_split[0] == "index") {
                        location.setIndex(parseIndex(line_split));
                } else if (line_split[0] == "methods") {
                        location.addMethods(parseMethods(line_split));
                } else if (line_split[0] == "cgi_path") {
                        location.setCgiPath(parseCgiPath(line_split));
                } else if (line_split[0] == "autoindex") {
                        location.setAutoIndex(parseAutoIndex(line_split));
                } else if (line_split[0] == "}" and line_split.size() == 1) {
                        break;
                } else {
                        file.close();
                        throw WebservError::ConfigurationException("unexpected token in line : '" + line + "'");
                }
        }
        return location;
}

i32 Parser::parseServerPort(const vector< string > &line_split) {
        if (line_split.size() != 2 or line_split[1].size() >= 5) {
                throw WebservError::ConfigurationException("bad configuration : " + line_split[0]);
        }

        if (!isValidPort(line_split[1])) {
                throw WebservError::ConfigurationException("bad port configuration for : " + line_split[1]);
        }

        i32 port = to_number< i32 >(line_split[1]);

        if (!isListeningPortUnique(port)) {
                throw WebservError::ConfigurationException("duplicate found for listen : " + line_split[1]);
        }

        addPortToSet(port);
        return port;
}

string Parser::parseRoot(const vector< string > &line_split) {
        if (line_split.size() != 2 or line_split[1][0] != '/') {
                throw WebservError::ConfigurationException("bad configuration : " + line_split[0]);
        }
        return line_split[1];
}

string Parser::parseIndex(const vector< string > &line_split) {
        if (line_split.size() != 2 or !stringEndsWith(line_split[1], ".html")) {
                throw WebservError::ConfigurationException("bad configuration : " + line_split[0]);
        }
        return line_split[1];
}

string Parser::parseServerName(const vector< string > &line_split) {
        if (line_split.size() != 2) {
                throw WebservError::ConfigurationException("bad configuration : " + line_split[0]);
        }

        if (!isValidServerName(line_split[1])) {
                throw WebservError::ConfigurationException("bad server name for : " + line_split[1]);
        }

        if (!isServerNameUnique(line_split[1])) {
                throw WebservError::ConfigurationException("duplicate found for server name : " + line_split[1]);
        }

        if (line_split[0] == "localhost") {
                addServerNameToSet("0.0.0.0");
                return "0.0.0.0";
        } else {
                addServerNameToSet(line_split[1]);
                return line_split[1];
        }
}

string Parser::parseLocationPath(const vector< string > &line_split) {
        if (line_split.size() != 3 or line_split[2] != "{") {
                throw WebservError::ConfigurationException("bad configuration : " + line_split[0]);
        }

        if (!stringStartsWith(line_split[1], "/")) {
                throw WebservError::ConfigurationException("bad path : " + line_split[0]);
        }

        return line_split[1];
}

usize Parser::parseMaxBodySize(const vector< string > &line_split) {
        if (line_split.size() != 2) {
                throw WebservError::ConfigurationException("bad configuration : " + line_split[0]);
        }
        return to_number< usize >(line_split[1]);
}

pair< i32, string > Parser::parseErrorPage(const vector< string > &line_split) {
        if (line_split.size() != 3) {
                throw WebservError::ConfigurationException("bad configuration : " + line_split[0]);
        }

        if (!isValidErrorPage(line_split)) {
                throw WebservError::ConfigurationException("bad configuration for : " + line_split[1] + " -> " + line_split[2]);
        }

        i32 error_code = to_number< i32 >(line_split[1]);
        return std::make_pair(error_code, line_split[2]);
}

bool Parser::parseAutoIndex(const vector< string > &line_split) {
        if (line_split.size() != 2) {
                throw WebservError::ConfigurationException("bad configuration : " + line_split[0]);
        }

        if (line_split[1] == "on") {
                return true;
        } else if (line_split[1] == "off") {
                return false;
        } else {
                throw WebservError::ConfigurationException("bad configuration for : " + line_split[0] + " invalid token -> " + line_split[1]);
        }
}

string Parser::parseCgiPath(const vector< string > &line_split) {
        if (line_split.size() != 2) {
                throw WebservError::ConfigurationException("bad configuration : " + line_split[0]);
        }

        if (!stringStartsWith(line_split[1], "/")) {
                throw WebservError::ConfigurationException("bad configuration for : " + line_split[0] + " invalid cgi_path -> " + line_split[1]);
        }

        if (!stringEndsWith(line_split[1], ".py") and !stringEndsWith(line_split[1], ".php") and !stringEndsWith(line_split[1], ".sh")) {
                throw WebservError::ConfigurationException("bad configuration for cgi_path : " + line_split[1] + " webserv only support .php/.py/.sh");
        }
        return line_split[1];
}

set< string > Parser::parseMethods(const vector< string > &line_split) {
        if (line_split.size() < 2) {
                throw WebservError::ConfigurationException("bad configuration : " + line_split[0]);
        }

        set< string > methods;
        for (usize i = 1; i < line_split.size(); i++) {
                if (line_split[i].find(",") != string::npos) {
                        string method = line_split[i].substr(0, line_split[i].find(","));
                        if (method == "GET" or method == "POST" or method == "DELETE") {
                                methods.insert(method);
                        } else {
                                throw WebservError::ConfigurationException("bad configuration for : " + line_split[0] + " invalid token -> " + method);
                        }
                } else {
                        string method = line_split[i];
                        if (method == "GET" or method == "POST" or method == "DELETE") {
                                methods.insert(method);
                        } else {
                                throw WebservError::ConfigurationException("bad configuration for : " + line_split[0] + " invalid token -> " + method);
                        }
                }
        }
        return methods;
}

bool Parser::isValidPort(const string &port) {
        if (port.empty()) {
                return false;
        } else if (!stringIsAll(port, std::isdigit)) {
                return false;
        } else {
                i32 port_num = to_number< i32 >(port);
                if (port_num < 1024 or port_num > 65536) {
                        return false;
                }
                return true;
        }
}

bool Parser::isValidServerName(const string &server_name) {
        if (server_name.empty()) {
                return false;
        }

        if (server_name == "localhost") {
                return true;
        }

        vector< string > name = split(server_name, ".");
        i32              num  = 0;

        for (usize i = 0; i < name.size(); i++) {
                num = to_number< i32 >(name[i]);
                if (num < 0 or num > 255) {
                        return false;
                }
        }
        return true;
}

bool Parser::isValidErrorPage(const vector< string > &line_split) {
        if (line_split.size() != 3) {
                return false;
        }

        i32 error_code = to_number< i32 >(line_split[1]);
        if (error_code < 100 or error_code > 600) {
                return false;
        }

        if (!stringStartsWith(line_split[2], "/") or !stringEndsWith(line_split[2], ".html")) {
                return false;
        }
        return true;
}

bool Parser::isListeningPortUnique(i32 port) {
        if (_listening_ports.find(port) != _listening_ports.end()) {
                return false;
        }
        return true;
}

bool Parser::isServerNameUnique(const string &server_name) {
        if (_servers_name.find(server_name) != _servers_name.end()) {
                return false;
        }
        return true;
}

void Parser::addPortToSet(i32 port) {
        _listening_ports.insert(port);
}

void Parser::addServerNameToSet(const string &server_name) {
        _servers_name.insert(server_name);
}

std::ostream &operator<<(std::ostream &os, const Parser &self) {
        os << "Parser:" << std::endl;

        // Print server blocks
        os << "SERVER BLOCKS:" << std::endl;
        const std::vector< Server > &servers = self.getServers();
        for (usize i = 0; i < servers.size(); ++i) {
                os << "server[" + to_string(i) + "] {" << std::endl;
                os << servers[i] << std::endl;
                os << "}" << std::endl;
        }

        // Print listening ports
        os << "LISTENING PORTS:" << std::endl;
        const std::set< i32 > &ports = self.getListeningPorts();
        os << "[";
        for (std::set< i32 >::const_iterator it = ports.begin(); it != ports.end(); ++it) {
                if (it != ports.begin()) {
                        os << ", ";
                }
                os << *it;
        }
        os << "]" << std::endl;

        // Print server names
        os << "SERVER NAMES:" << std::endl;
        const std::set< std::string > &names = self.getServersName();
        os << "[";
        for (std::set< std::string >::const_iterator it = names.begin(); it != names.end(); ++it) {
                if (it != names.begin()) {
                        os << ", ";
                }
                os << *it;
        }
        os << "]" << std::endl;

        return os;
}
