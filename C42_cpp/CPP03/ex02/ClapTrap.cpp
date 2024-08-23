/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 12:20:40 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/22 12:20:41 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("none"), _hp(10), _ep(10), _dp(0) {
	std::cout << "ClapTrap : " << __PRETTY_FUNCTION__ << " : default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _ep(10), _dp(0) {
	std::cout << "ClapTrap : " << __PRETTY_FUNCTION__ << " : custom constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &other) : _name(other._name), _hp(other._hp), _ep(other._ep), _dp(other._dp) {
	std::cout << "ClapTrap : " << __PRETTY_FUNCTION__ << " : copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other) {
	std::cout << "ClapTrap : " << __PRETTY_FUNCTION__ << " : assignment constructor called" << std::endl;
	if (this != &other) {
		this->_name = other._name;
		this->_hp = other._hp;
		this->_ep = other._ep;
		this->_dp = other._dp;
	}
	return (*this);
}

bool ClapTrap::isDead() const {
	return (_hp == 0);
}

bool ClapTrap::hasEnergy() const {
	return (_ep != 0);
}

void ClapTrap::attack(const std::string &target) {
	if (isDead()) {
		std::cout << "ClapTrap: " << _name << " can't attack because he is dead" << std::endl;
	} else if (!hasEnergy()) {
		std::cout << "ClapTrap: " << _name << " can't attack because he doesn't have energy" << std::endl;
	} else {
		std::cout << "ClapTrap: " << _name << " attacks " << target << ", causing " << _dp << " points of damage!" << std::endl;
		_ep -= 1;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (isDead()) {
		std::cout << "ClapTrap: " << _name << " can't take damage because he is dead" << std::endl;
	} else if (!hasEnergy()) {
		std::cout << "ClapTrap: " << _name << " can't attack because he doesn't have energy" << std::endl;
	} else {
		std::cout << "ClapTrap: " << _name << " takes " << amount << " points of damage!" << std::endl;
		_hp = (amount >= _hp) ? 0 : (_hp - amount);
	}
}
void ClapTrap::beRepaired(unsigned int amount) {
	if (isDead()) {
		std::cout << "ClapTrap: " << _name << " can't be repaired because he is dead" << std::endl;
	} else if (!hasEnergy()) {
		std::cout << "ClapTrap: " << _name << " can't repair because he doesn't have energy" << std::endl;
	} else {
		std::cout << "ClapTrap: " << _name << " repaired " << amount << " points of damage!" << std::endl;
		_hp += amount;
		_ep -= 1;
	}
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap : " << __PRETTY_FUNCTION__ << " : default destructor called" << std::endl;
}
