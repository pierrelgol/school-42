/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 14:00:11 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/25 14:00:14 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "WrongCat : " << __PRETTY_FUNCTION__ << " default ctor called" << std::endl;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type) {
	std::cout << "WrongCat : " << __PRETTY_FUNCTION__ << " custom ctor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &other) : WrongAnimal(other) {
	std::cout << "WrongCat : " << __PRETTY_FUNCTION__ << " copy ctor called" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &other) {
	std::cout << "WrongCat : " << __PRETTY_FUNCTION__ << " assignment ctor called" << std::endl;
	if (this != &other) {
		this->_type = other._type;
	}
	return (*this);
}

void WrongCat::makeSound() const {
	std::cout << "WrongCat : *Grrrr!*" << std::endl;
}

WrongCat::~WrongCat() {
}
