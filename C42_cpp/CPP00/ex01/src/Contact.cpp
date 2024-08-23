/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:48:51 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/13 16:48:51 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

#include "Contact.hpp"
#include <iomanip>

// Still don't understand that shit there's no excuse for allowing such bad
// programming in life absolutely fucking terrible language
// made for retards
Contact::Contact() {
}

// I swear that this is the worst code I've seen in my entire life
Contact::Contact(std::string first_name, std::string last_name, std::string nick_name, std::string phone_number, std::string darkest_secret)
    : FirstName(first_name), LastName(last_name), NickName(nick_name), PhoneNumber(phone_number), DarkestSecret(darkest_secret) {
}

void Contact::print(usize index, PrintStyle style) const {
	// Oh yes let's have a language full of syntactic sugar
	// but let's keep a terrible switch syntax. WTF ????
	switch (style) {
	case print_header: {
		printColumn(index);
		printColumn(FirstName);
		printColumn(LastName);
		printColumn(NickName);
		std::cout << std::endl;
	} break;

	case print_full: {
		std::cout << "First Name     : " << FirstName << std::endl;
		std::cout << "Last Name      : " << LastName << std::endl;
		std::cout << "Nick Name      : " << NickName << std::endl;
		std::cout << "Phone Number   : " << PhoneNumber << std::endl;
		std::cout << "Darkest Secret : " << DarkestSecret << std::endl;
	} break;
	}
}

void Contact::printColumn(const std::string attribute) const {
	std::string formated = std::string(attribute);

	if (formated.length() > 10) {
		formated = formated.substr(0, 9);
		formated.insert(9, 1, '.');
	}

	// What the actual fuck is that syntax to set the width ?????
	// why can't we get the fucking simple printf("%10s | ", formated);
	// what a joke of a language
	std::cout << std::right << std::setw(10) << formated << " | ";
}

void Contact::printColumn(usize number) const {
	std::cout << std::right << std::setw(10) << number << " | ";
}

Contact::~Contact(void) {
}
