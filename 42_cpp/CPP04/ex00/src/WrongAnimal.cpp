/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 13:49:40 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/25 13:49:41 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "WrongAnimal : " << __PRETTY_FUNCTION__ << " default ctor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
	std::cout << "WrongAnimal : " << __PRETTY_FUNCTION__ << " custom ctor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &other) : _type(other._type) {
	std::cout << "WrongAnimal : " << __PRETTY_FUNCTION__ << " copy ctor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &other) {
	std::cout << "WrongAnimal : " << __PRETTY_FUNCTION__ << " assignment ctor called" << std::endl;
	if (this != &other) {
		this->_type = other._type;
	}
	return (*this);
}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal :  *...*" << std::endl;
}

std::string WrongAnimal::getType() const {
	return (this->_type);
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal : " << __PRETTY_FUNCTION__ << " default dtor called" << std::endl;
}
