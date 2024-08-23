/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:21:37 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/21 12:21:37 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fixed_point(0) {
}

Fixed::Fixed(const Fixed &other) {
	*this = other;
}

Fixed::Fixed(const int value) {
	this->_fixed_point = (value << this->_factional_bits);
}

Fixed::Fixed(const float value) {
	this->_fixed_point = (int) roundf(value * (1 << this->_factional_bits));
}

Fixed &Fixed::operator=(const Fixed &other) {
	if (this != &other)
		this->_fixed_point = other._fixed_point;
	return (*this);
}

bool Fixed::operator>(Fixed const &other) const {
	return (this->_fixed_point > other.getRawBits());
}

bool Fixed::operator>=(Fixed const &other) const {
	return (this->getRawBits() >= other.getRawBits());
}

bool Fixed::operator<(Fixed const &other) const {
	return (this->getRawBits() < other.getRawBits());
}

bool Fixed::operator<=(Fixed const &other) const {
	return (this->getRawBits() <= other.getRawBits());
}

bool Fixed::operator==(Fixed const &other) const {
	return (this->getRawBits() == other.getRawBits());
}

bool Fixed::operator!=(Fixed const &other) const {
	return (this->getRawBits() != other.getRawBits());
}

Fixed Fixed::operator+(Fixed const &other) const {
	return (Fixed((this->getRawBits() + other.getRawBits()) >> this->_factional_bits));
}

Fixed Fixed::operator-(Fixed const &other) const {
	return (Fixed((this->getRawBits() - other.getRawBits()) >> this->_factional_bits));
}

Fixed Fixed::operator*(Fixed const &other) const {
	Fixed result(0);
	result.setRawBits((this->getRawBits() * other.getRawBits()) >> this->_factional_bits);
	return (result);
}

Fixed Fixed::operator/(Fixed const &other) const {
	return (Fixed((this->getRawBits() / other.getRawBits()) >> this->_factional_bits));
}

Fixed &Fixed::operator++(void) {
	this->_fixed_point++;
	return (*this);
}

Fixed &Fixed::operator--(void) {
	this->_fixed_point--;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed result(*this);
	operator++();
	return (result);
}

Fixed Fixed::operator--(int) {
	Fixed result(*this);
	operator--();
	return (result);
}

int Fixed::getRawBits(void) const {
	return (this->_fixed_point);
}

void Fixed::setRawBits(int const raw) {
	this->_fixed_point = raw;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return (a < b ? a : b);
}
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b ? a : b);
}
Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return (a > b ? a : b);
}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	return (a > b ? a : b);
}

float Fixed::floatFromInt(void) const {
	return ((float) this->_fixed_point / (float) (1 << this->_factional_bits));
}

int Fixed::intFromFloat(void) const {
	return (int) (this->_fixed_point >> this->_factional_bits);
}

std::ostream &operator<<(std::ostream &ostream, const Fixed &self) {
	ostream << self.floatFromInt();
	return (ostream);
}

Fixed &min(Fixed &a, Fixed &b) {
	return (a < b ? a : b);
}

Fixed &max(Fixed &a, Fixed &b) {
	return (a > b ? a : b);
}

Fixed::~Fixed(void) {
}

// POV : YOU ARE FORCED TO USE CPP
//
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡤⠶⠒⠋⠉⠉⠉⠉⠉⠉⠉⠉⠑⠲⢤⡀⠀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⣀⡴⠊⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠒⠦⡀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⢀⣠⠞⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢙⣦⡀⠀⠀
// ⠀⠀⠀⠀⣰⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢷⠀⠀
// ⠀⠀⠀⣼⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣧⠀
// ⠀⠀⢰⡃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡄
// ⠀⠀⣼⣛⡂⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠤⠬⡥⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣧
// ⠀⢰⠃⠜⠌⡥⡂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡒⠬⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿
// ⠀⡿⠀⠀⠀⠀⢣⡁⠄⠀⠀⠀⠀⠀⠀⠔⣫⠇⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿
// ⠀⡇⠀⠀⢀⣤⣀⠈⠃⠁⠀⠀⠀⠀⠀⠀⠀⣠⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼
// ⠀⣷⠀⠀⣺⣿⣿⠂⠀⢠⡄⠀⠀⠀⠀⠀⠀⢿⣿⡷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⡏
// ⢠⠏⠀⠀⠀⠋⠀⠀⠀⣿⣇⠀⠀⠀⠀⠀⠀⠀⠁⠘⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡼⠀
// ⣿⠀⠀⠀⠅⠂⠀⠀⣸⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠰⠀⠀⠀⠀⠀⠀⠀⣶⠀⠀⠀⠀⠀⣰⠃⠀
// ⢿⠀⠀⠀⢘⠀⠀⢀⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⠀⠀⠀⠀⠀⠀⠀⣹⢀⠀⠀⠀⡼⠁⠀⠀
// ⠈⣇⠀⠀⡡⠀⠀⣼⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⠄⠀⠀⠀⠀⠀⢰⡏⠈⠀⠀⣼⠁⠀⠀⠀
// ⠀⠘⣆⠀⡬⠀⠀⠿⠿⠿⠿⠿⠿⠿⠿⠗⠀⠀⠀⢠⠁⠀⠀⠀⠀⢀⡾⠁⠁⠀⠀⣿⠀⠀⠀⠀
// ⠀⠀⠘⢦⣙⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀⠀⠀⠀⣠⠞⡵⠀⠀⠀⠀⣿⠀⠀⠀⠀
// ⠀⠀⠀⠈⣿⠀⠰⣿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠀⠀⢀⡃⢀⣤⠞⠁⠀⡇⠀⠀⠀⠀⣿⠀⠀⠀⠀
// ⠀⠀⠀⠀⠽⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢈⡷⠛⠁⠀⠀⠀⠻⡄⠀⠀⠀⠘⣇⠀⠀⠀
// ⠀⠀⠀⠀⠀⠈⢣⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡴⠋⠀⠀⠀⠀⠀⠀⠀⠃⠀⠀⠀⠀⢿⡀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠈⠙⠲⠤⣤⠤⠤⠴⠖⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠚⠶⣤⠀⠀⠀⠀⢳⡀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⠒⠀⠀⠚⠋⠉⠉⠙⠛⠒⠒⠒⠒⠒⠒⠒⠛⠛⠉⠉⠉⠉⠙⠀
