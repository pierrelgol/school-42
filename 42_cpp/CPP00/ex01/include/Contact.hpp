/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:43:07 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/13 16:43:08 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "Types.hpp"
#include <iomanip>
#include <iostream>

enum PrintStyle { print_header, print_full };

class Contact {
      private:
	std::string FirstName;
	std::string LastName;
	std::string NickName;
	std::string PhoneNumber;
	std::string DarkestSecret;

      public:
	Contact();

	Contact(std::string first_name, std::string last_name, std::string nick_name, std::string phone_number, std::string darkest_secret);
	// const at the end ???? why this language suck this much ?
	void print(usize index, PrintStyle style) const;
	void printColumn(const std::string atribute) const;
	void printColumn(usize number) const;

	// What the actual fuck is this shit ????
	~Contact(void);
};

#endif // CONTACT_HPP
