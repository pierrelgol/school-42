/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 07:51:24 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/21 07:51:24 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>

int main(void) {
	std::string string = "HI THIS IS BRAIN";
	// std::string &stringREF = string; this is the same as using const ?
	std::string &stringREF = string;
	std::string *stringPTR = &string;

	std::cout << "-------------------------------------------------------------" << std::endl;
	std::cout << std::setfill(' ') << std::setw(16) << "name" << "  |  " << std::setw(16) << "address" << "  |  " << std::setw(16) << "value" << "  |  " << std::endl;
	std::cout << std::setfill(' ') << std::setw(16) << "string" << "  |  " << std::setw(16) << &string << "  |  " << std::setw(16) << string << "  |  " << std::endl;
	std::cout << std::setfill(' ') << std::setw(16) << "stringREF" << "  |  " << std::setw(16) << &stringREF << "  |  " << std::setw(16) << stringREF << "  |  " << std::endl;
	std::cout << std::setfill(' ') << std::setw(16) << "stringPTR" << "  |  " << std::setw(16) << stringPTR << "  |  " << std::setw(16) << *stringPTR << "  |  " << std::endl;
	std::cout << "-------------------------------------------------------------" << std::endl;

	return (0);
}
