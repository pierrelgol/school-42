/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 13:41:35 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/25 13:41:35 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog : " << __PRETTY_FUNCTION__ << " default ctor called" << std::endl;
}

Dog::Dog(std::string type) : Animal(type) {
	std::cout << "Dog : " << __PRETTY_FUNCTION__ << " custom ctor called" << std::endl;
}

Dog::Dog(Dog const &other) : Animal(other) {
	std::cout << "Dog : " << __PRETTY_FUNCTION__ << " copy ctor called" << std::endl;
}

Dog &Dog::operator=(Dog const &other) {
	std::cout << "Dog : " << __PRETTY_FUNCTION__ << " assignment ctor called" << std::endl;
	if (this != &other) {
		this->_type = other._type;
	}
	return (*this);
}

void Dog::makeSound() const {
	std::cout << "Dog : *Bark!*" << std::endl;
}

Dog::~Dog() {
}
