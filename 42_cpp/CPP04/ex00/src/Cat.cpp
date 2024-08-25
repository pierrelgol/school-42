/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 13:47:42 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/25 13:47:43 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat : " << __PRETTY_FUNCTION__ << " default ctor called" << std::endl;
}

Cat::Cat(std::string type) : Animal(type) {
	std::cout << "Cat : " << __PRETTY_FUNCTION__ << " custom ctor called" << std::endl;
}

Cat::Cat(Cat const &other) : Animal(other) {
	std::cout << "Cat : " << __PRETTY_FUNCTION__ << " copy ctor called" << std::endl;
}

Cat &Cat::operator=(Cat const &other) {
	std::cout << "Cat : " << __PRETTY_FUNCTION__ << " assignment ctor called" << std::endl;
	if (this != &other) {
		this->_type = other._type;
	}
	return (*this);
}

void Cat::makeSound() const {
	std::cout << "Cat : *Meow!*" << std::endl;
}

Cat::~Cat() {
}
