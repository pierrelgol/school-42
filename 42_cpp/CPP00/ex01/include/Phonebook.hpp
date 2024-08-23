/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:53:05 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/13 16:53:05 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#define CONTACT_MAX 8
#define CLEAR "\033[H\033[J"

#include "Contact.hpp"
#include "Types.hpp"
#include <iomanip>
#include <iostream>

class PhoneBook {
      private:
	Contact Contacts[CONTACT_MAX];
	usize   Count;

      public:
	PhoneBook();
	void display();
	void printColumn(const std::string atribute) const;
	bool add();
	bool search();
	bool exit();
	bool convert(std::string maybe_valid_number, usize &out_result);

	// Still doesn't make any sense
	~PhoneBook(void);
};

#endif // PHONEBOOK_HPP
