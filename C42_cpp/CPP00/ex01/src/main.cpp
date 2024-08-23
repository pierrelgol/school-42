/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:49:14 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/13 16:49:14 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "Phonebook.hpp"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

int main() {
	PhoneBook phonebook = PhoneBook();

	std::cout << CLEAR;
	while (true) {
		std::string inputs;

		std::cout << "\tPhoneBook Commands\n"
		             "ADD    : creates a new Contact\n"
		             "SEARCH : display/select existing contacts\n"
		             "EXIT   : quit this program\n";

		do {
			std::cin >> inputs;
		} while (inputs.length() == 0);

		if (inputs == "ADD") {
			phonebook.add();
			std::cout << CLEAR;
			continue;
		}

		if (inputs == "SEARCH") {
			phonebook.search();
			continue;
		}

		if (inputs == "EXIT") {
			phonebook.exit();
			return (0);
		} else {
			std::cout << CLEAR;
			continue;
		}
	}

	return 0;
}
