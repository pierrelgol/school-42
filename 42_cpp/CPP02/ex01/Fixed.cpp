/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:12:04 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/21 12:12:05 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fixed_point(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) {
	std::cout << "Copy constructor called" << std::endl;
	this->_fixed_point = fixed.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Assignment operator called" << std::endl;
	this->_fixed_point = other.getRawBits();
	return *this;
}

Fixed::Fixed(int const value) {
	std::cout << "Int constructor called" << std::endl;
	this->_fixed_point = (value << _fractional_bits);
}

Fixed::Fixed(float const value) {
	std::cout << "Float constructor called" << std::endl;
	this->_fixed_point = int(roundf(value * (1 << _fractional_bits)));
}

int Fixed::getRawBits(void) const {
	return this->_fixed_point;
}

void Fixed::setRawBits(int const raw) {
	this->_fixed_point = raw;
}

float Fixed::floatFromInt(void) const {
	return float(this->_fixed_point) / (1 << _fractional_bits);
}

int Fixed::intFromFloat(void) const {
	return this->_fixed_point >> _fractional_bits;
}

std::ostream &operator<<(std::ostream &ostream, const Fixed &self) {
	ostream << self.floatFromInt();
	return ostream;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}
