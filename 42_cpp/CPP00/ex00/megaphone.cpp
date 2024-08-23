/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:28:14 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/13 16:28:14 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include <iostream>

int main(int argc, char **argv) {
	if (argc != 1) {
		for (long i = 1; i < argc; ++i) {
			std::string word = std::string(argv[i]);
			for (unsigned long i = 0; i < word.length(); ++i)
				word.at(i) = std::toupper(word.at(i));
			std::cout << word << ' ';
		}

	} else {
		// this is the worst syntax I've seen in my entire life
		std::cout << " * LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	return (0);
}
