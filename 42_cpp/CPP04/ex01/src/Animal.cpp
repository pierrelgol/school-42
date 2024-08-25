/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 13:04:20 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/25 13:04:21 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal : " << __PRETTY_FUNCTION__ << " default ctor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type) {
	std::cout << "Animal : " << __PRETTY_FUNCTION__ << " custom ctor called" << std::endl;
}

Animal::Animal(Animal const &other) : _type(other._type) {
	std::cout << "Animal : " << __PRETTY_FUNCTION__ << " copy ctor called" << std::endl;
}

Animal &Animal::operator=(Animal const &other) {
	std::cout << "Animal : " << __PRETTY_FUNCTION__ << " assignment ctor called" << std::endl;
	if (this != &other) {
		this->_type = other._type;
	}
	return (*this);
}

void Animal::makeSound() const {
	std::cout << "Animal :  *...*" << std::endl;
}

std::string Animal::getType() const {
	return (this->_type);
}

Animal::~Animal() {
	std::cout << "Animal : " << __PRETTY_FUNCTION__ << " default dtor called" << std::endl;
}
