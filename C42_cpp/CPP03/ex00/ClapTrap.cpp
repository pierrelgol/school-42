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

// useless dogshit programming, like why am I waisting my time doing
// such a profoundly useless work. Like OOP is such a worthless programming
// paradigm, look at how much trash I have to write just to get what's essentially
// a struct on the stack and print stuff like why ???
ClapTrap::ClapTrap() : _name("none"), _hp(10), _ep(10), _dp(0) {
	std::cout << __PRETTY_FUNCTION__ << " : default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _ep(10), _dp(0) {
	std::cout << __PRETTY_FUNCTION__ << " : custom constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &other) : _name(other._name), _hp(other._hp), _ep(other._ep), _dp(other._dp) {
	std::cout << __PRETTY_FUNCTION__ << " : copy constructor called" << std::endl;
}

// still trash
ClapTrap &ClapTrap::operator=(ClapTrap const &other) {
	std::cout << __PRETTY_FUNCTION__ << " : assignment constructor called" << std::endl;
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
		std::cout << _name << " can't attack because he is dead" << std::endl;
	} else if (!hasEnergy()) {
		std::cout << _name << " can't attack because he doesn't have energy" << std::endl;
	} else {
		std::cout << _name << " attacks " << target << ", causing " << _dp << " points of damage!" << std::endl;
		_ep -= 1;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (isDead()) {
		std::cout << _name << " can't take damage because he is dead" << std::endl;
	} else if (!hasEnergy()) {
		std::cout << _name << " can't attack because he doesn't have energy" << std::endl;
	} else {
		std::cout << _name << " takes " << amount << " points of damage!" << std::endl;
		_hp = (amount >= _hp) ? 0 : (_hp - amount);
	}
}
void ClapTrap::beRepaired(unsigned int amount) {
	if (isDead()) {
		std::cout << _name << " can't be repaired because he is dead" << std::endl;
	} else if (!hasEnergy()) {
		std::cout << _name << " can't repair because he doesn't have energy" << std::endl;
	} else {
		std::cout << _name << " repaired " << amount << " points of damage!" << std::endl;
		_hp += amount;
		_ep -= 1;
	}
}

ClapTrap::~ClapTrap() {
	std::cout << __PRETTY_FUNCTION__ << " : default destructor called" << std::endl;
}
