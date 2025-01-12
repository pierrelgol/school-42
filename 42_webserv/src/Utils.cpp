/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 11:43:45 by pollivie          #+#    #+#             */
/*   Updated: 2025/01/02 11:43:45 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"
#include <cerrno>
#include <fcntl.h>
#include <sys/socket.h>
#include <unistd.h>
#include <climits>
#include <sys/stat.h>
#include <dirent.h>
#include <sstream>
#include <fstream>


string trim(const string& str) {
        string::const_iterator start = str.begin();
        string::const_iterator end   = str.end();

        while (start != end && isspace(*start)) {
                ++start;
        }

        while (end != start && isspace(*(end - 1))) {
                --end;
        }

        return string(start, end);
}


vector< string > split(const string& str, const string& delimiters) {
        vector< string > result;
        usize            start = 0;
        usize            end   = 0;

        while ((end = str.find_first_of(delimiters, start)) != string::npos) {
                if (end > start) {
                        result.push_back(str.substr(start, end - start));
                }
                start = end + 1;
        }

        if (start < str.length()) {
                result.push_back(str.substr(start));
        }

        return result;
}

isize readAll(i32 fd, string& out_buffer) {
        char  buffer[BUFFER_SIZE];
        isize total_bytes_read = 0;
        isize bytes_read;

        while (true) {
                bytes_read = read(fd, buffer, BUFFER_SIZE);

                if (bytes_read < 0) {
                        return -1;
                }

                if (bytes_read == 0) {
                        break;
                }

                out_buffer.append(buffer, static_cast< usize >(bytes_read));
                total_bytes_read += bytes_read;

                if (bytes_read < static_cast< isize >(BUFFER_SIZE)) {
                        break;
                }
        }

        return total_bytes_read;
}

isize recvAll(i32 fd, string& out_buffer) {
        char  buffer[BUFFER_SIZE];
        isize total_bytes_read = 0;
        isize bytes_read;

        while (true) {
                bytes_read = recv(fd, buffer, BUFFER_SIZE, 0);

                if (bytes_read < 0) {
                        return -1;
                }

                if (bytes_read == 0) {
                        break;
                }

                out_buffer.append(buffer, static_cast< usize >(bytes_read));
                total_bytes_read += bytes_read;

                if (bytes_read < static_cast< isize >(BUFFER_SIZE)) {
                        break;
                }
        }

        return total_bytes_read;
}


isize openReadAll(const string& file_name, string& out) {
        i32 fd = open(file_name.c_str(), O_RDONLY);

        if (fd == -1) {
                return -1;
        } else {
                isize bytes_read = readAll(fd, out);
                close(fd);
                return bytes_read;
        }
}

bool stringContains(const string& haystack, const string& needle) {
        return haystack.find(needle) != string::npos;
}

bool stringStartsWith(const string& haystack, const string& needle) {
        return haystack.compare(0, needle.size(), needle) == 0;
}

bool stringEndsWith(const string& haystack, const string& needle) {
        if (needle.size() > haystack.size()) {
                return false;
        }
        return haystack.compare(haystack.size() - needle.size(), needle.size(), needle) == 0;
}

bool splitContains(const vector< string >& haystack, const string& needle) {
        for (vector< string >::const_iterator it = haystack.begin(); it != haystack.end(); ++it) {
                if (*it == needle) {
                        return true;
                }
        }
        return false;
}

bool splitStartsWith(const vector< string >& haystack, const string& needle) {
        if (haystack.empty()) {
                return false;
        }
        return haystack.front() == needle;
}

bool splitEndsWith(const vector< string >& haystack, const string& needle) {
        if (haystack.empty()) {
                return false;
        }
        return haystack.back() == needle;
}

isize stringCount(const string& haystack, const string& needle) {
        if (needle.empty()) {
                return 0;
        }

        isize             count = 0;
        string::size_type pos   = 0;
        while ((pos = haystack.find(needle, pos)) != string::npos) {
                ++count;
                pos += needle.size();
        }

        return count;
}

isize splitCount(const vector< string >& haystack, const string& needle) {
        isize count = 0;
        for (vector< string >::const_iterator it = haystack.begin(); it != haystack.end(); ++it) {
                if (*it == needle) {
                        ++count;
                }
        }
        return count;
}

string toAbsolutePath(const string& path) {
        char buffer[PATH_MAX];
        if (realpath(path.c_str(), buffer) != NULL) {
                return string(buffer);
        }
        return "";
}

bool isValidFile(const string& path, i32 flag) {
        return access(path.c_str(), flag) == 0;
}

bool stringIsAll(const string& str, i32 (*func)(i32)) {
        for (string::const_iterator it = str.begin(); it != str.end(); ++it) {
                if (!func(static_cast< unsigned char >(*it))) {
                        return false;
                }
        }
        return true;
}

isize openWriteAll(const string& file_name, const string& buffer, i32 permision, i32 flag) {
        i32 file_fd = open(file_name.c_str(), permision, flag);
        if (file_fd == -1) {
                return -1;
        } else {
                isize wbytes = write(file_fd, buffer.c_str(), buffer.size());
                close(file_fd);
                return wbytes;
        }
}

string normalizePath(string path) {
        size_t i = 0;
        while (i + 1 < path.size()) {
                if (path[i] == '/' && path[i + 1] == '/') {
                        path.erase(i, 1);
                } else {
                        i++;
                }
        }
        return path;
}

string normalizeUrl(const string& url) {
        string normalized = url;
        usize  query_pos  = normalized.find('?');
        if (query_pos != string::npos) {
                normalized = normalized.substr(0, query_pos);
        }
        while (!normalized.empty() && normalized[normalized.length() - 1] == '/') {
                normalized = normalized.substr(0, normalized.length() - 1);
        }
        return normalized;
}


isize sendAll(i32 fd, const string& buffer) {
        return send(fd, buffer.c_str(), buffer.size(), 0);
}


bool isDirectory(const string& path) {
        struct stat file_stat;
        if (stat(path.c_str(), &file_stat) == -1) {
                return false;
        }
        return S_ISDIR(file_stat.st_mode);
}


string generateDirectoryListing(const string& directory_path) {
        DIR* dir = opendir(directory_path.c_str());
        if (!dir) {
                return "<html><body><h1>Error: Unable to access directory</h1></body></html>";
        }

        std::ostringstream html;
        html << "<html><body><h1>Directory Listing for " << directory_path << "</h1><ul>";

        struct dirent* entry;
        while ((entry = readdir(dir)) != NULL) {
                string entry_name = entry->d_name;
                if (entry_name == "." || entry_name == "..") {
                        continue;
                }
                html << "<li><a href=\"" << entry_name << "\">" << entry_name << "</a></li>";
        }

        html << "</ul></body></html>";
        closedir(dir);
        return html.str();
}

string determineContentType(const string& file_path) {
        static map< string, string > mime_types;
        if (mime_types.empty()) {
                mime_types[".html"] = "text/html";
                mime_types[".htm"]  = "text/html";
                mime_types[".css"]  = "text/css";
                mime_types[".js"]   = "application/javascript";
                mime_types[".json"] = "application/json";
                mime_types[".png"]  = "image/png";
                mime_types[".jpg"]  = "image/jpeg";
                mime_types[".jpeg"] = "image/jpeg";
                mime_types[".gif"]  = "image/gif";
                mime_types[".svg"]  = "image/svg+xml";
                mime_types[".txt"]  = "text/plain";
                mime_types[".pdf"]  = "application/pdf";
                mime_types[".zip"]  = "application/zip";
                mime_types[".tar"]  = "application/x-tar";
        }

        string::size_type pos = file_path.rfind('.');
        if (pos == string::npos) {
                return "application/octet-stream";
        }

        string                          extension = file_path.substr(pos);
        map< string, string >::iterator it        = mime_types.find(extension);
        if (it != mime_types.end()) {
                return it->second;
        }
        return "application/octet-stream";
}

bool parseUri(const string& uri, string& path, string& file, string& query) {
        string::size_type query_pos = uri.find('?');
        string::size_type last_slash_pos;

        if (query_pos != string::npos) {
                query = uri.substr(query_pos + 1);
                path  = uri.substr(0, query_pos);
        } else {
                path = uri;
        }

        last_slash_pos = path.rfind('/');
        if (last_slash_pos != string::npos && last_slash_pos < path.length() - 1) {
                file = path.substr(last_slash_pos + 1);
                path = path.substr(0, last_slash_pos + 1);
        }

        return true;
}

string joinPaths(const string& path1, const string& path2) {
        string normalized_path1 = path1;
        string normalized_path2 = path2;

        if (!normalized_path1.empty() && normalized_path1[normalized_path1.length() - 1] == '/') {
                normalized_path1.erase(normalized_path1.length() - 1);
        }


        if (!normalized_path2.empty() && normalized_path2[0] == '/') {
                normalized_path2.erase(0, 1);
        }


        string joined_path = normalized_path1 + "/" + normalized_path2;


        string normalized_path;
        for (string::size_type i = 0; i < joined_path.length(); ++i) {
                if (!(joined_path[i] == '/' && i > 0 && joined_path[i - 1] == '/')) {
                        normalized_path += joined_path[i];
                }
        }

        return normalized_path;
}

string decodeUrl(const string& str) {
        string decoded;
        for (size_t i = 0; i < str.size(); ++i) {
                if (str[i] == '%') {
                        if (i + 2 < str.size()) {
                                char hex[3] = {str[i + 1], str[i + 2], '\0'};
                                try {
                                        decoded += static_cast< char >(std::strtol(hex, NULL, 16));

                                } catch (std::exception& e) {
                                        return "";
                                }
                                i += 2;
                        } else {
                                return "";
                        }
                } else if (str[i] == '+') {
                        decoded += ' ';
                } else {
                        decoded += str[i];
                }
        }
        return decoded;
}
