/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:57:51 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/13 16:57:52 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Phonebook.hpp>

PhoneBook::PhoneBook() : Count(0) {
}

void PhoneBook::display() {
	printColumn("Index");
	printColumn("First Name");
	printColumn("Last Name");
	printColumn("Nick Name");
	std::cout << std::endl;
	// Where does Contacts come from ?? Idk up my ass probably
	// why is this programming language allergic to being readable ?
	for (usize i = 0; i < Count; ++i)
		Contacts[i].print(i, print_header);
	std::cout << std::endl;
}

bool PhoneBook::add() {
	usize index = (Count++) % CONTACT_MAX;

	std::cout << CLEAR << "Enter your First Name: " << '\n';
	std::string first_name;
	do {
		std::getline(std::cin, first_name);
	} while (first_name.length() == 0);

	std::cout << CLEAR << "Enter your Last Name: " << '\n';
	std::string last_name;
	do {
		std::getline(std::cin, last_name);
	} while (last_name.length() == 0);

	std::cout << CLEAR << "Enter your Nickname: " << '\n';
	std::string nick_name;
	do {
		std::getline(std::cin, nick_name);
	} while (nick_name.length() == 0);

	std::cout << CLEAR << "Enter your Phone Number: " << '\n';
	std::string phone_number;
	do {
		std::getline(std::cin, phone_number);
	} while (phone_number.length() == 0);

	std::cout << CLEAR << "Enter your Darkest Secret: " << '\n';
	std::string darkest_secret;
	do {
		std::getline(std::cin, darkest_secret);
	} while (darkest_secret.length() == 0);

	Contacts[index] = Contact(first_name, last_name, nick_name, phone_number, darkest_secret);
	if (Count >= CONTACT_MAX)
		Count = CONTACT_MAX;
	return (true);
}

void PhoneBook::printColumn(const std::string attribute) const {
	std::string formated = std::string(attribute);

	if (formated.length() > 10) {
		formated = formated.substr(0, 9);
		formated.insert(9, 1, '.');
	}

	std::cout << std::right << std::setw(10) << formated << " | ";
}
bool PhoneBook::convert(std::string maybe_valid_number, usize &out_result) {
	out_result = 0;
	for (usize i = 0; i < maybe_valid_number.length(); ++i) {
		const u8 ch = maybe_valid_number.at(i);
		if (ch <= '0' and ch >= '9')
			return (false);
		out_result = (ch - '0') + (out_result * 10);
	}
	return (true);
}

bool PhoneBook::search() {
	std::cout << CLEAR << "Select the contact with index [0-" << Count << "]." << '\n';
	display();
	std::string maybe_valid_index;
	do {
		// LoOk I'vE uSeD >> i GeT nO bItChEs. Like what the fuck is that bruv
		std::cin >> maybe_valid_index;
	} while (maybe_valid_index.length() == 0);
	usize index = 0;
	if (!convert(maybe_valid_index, index) or index > Count or index > CONTACT_MAX)
		return (false);
	else
		Contacts[index].print(index, print_full);
	return (true);
}

bool PhoneBook::exit() {
	return (true);
}

// still don't get it Retard language
PhoneBook::~PhoneBook(void) {
}
