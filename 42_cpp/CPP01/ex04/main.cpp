/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 09:20:10 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/21 09:20:10 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

void replaceStringInFile(const std::string &filename, const std::string &s1, const std::string &s2) {
	std::ifstream infile(filename.c_str());
	if (!infile.is_open()) {
		std::cerr << "Error: Could not open file " << filename << std::endl;
		return;
	}

	std::string   outFilename = filename + ".replace";
	std::ofstream outfile(outFilename.c_str());
	if (!outfile.is_open()) {
		std::cerr << "Error: Could not create output file " << outFilename << std::endl;
		infile.close();
		return;
	}

	std::string line;
	while (std::getline(infile, line)) {
		std::size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos) {
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}
		outfile << line << std::endl;
	}
	infile.close();
	outfile.close();
}

int main(int argc, char **argv) {
	// Check the number of arguments
	if (argc != 4) {
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return (1);
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (s1.empty()) {
		std::cerr << "Error: s1 cannot be an empty string." << std::endl;
		return (1);
	}
	replaceStringInFile(filename, s1, s2);

	return (0);
}
