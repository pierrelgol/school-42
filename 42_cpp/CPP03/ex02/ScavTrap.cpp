/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:07:17 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/22 14:07:17 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "ScavTrap : " << __PRETTY_FUNCTION__ << " : default constructor called" << std::endl;
	this->_hp = 100;
	this->_ep = 50;
	this->_dp = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap : " << __PRETTY_FUNCTION__ << " : custom constructor called" << std::endl;
	this->_hp = 100;
	this->_ep = 50;
	this->_dp = 20;
}

ScavTrap::ScavTrap(ScavTrap const &other) : ClapTrap(other) {
	std::cout << "ScavTrap : " << __PRETTY_FUNCTION__ << " : copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &other) {
	std::cout << "ScavTrap : " << __PRETTY_FUNCTION__ << " : assignment constructor called" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return (*this);
}

void ScavTrap::attack(std::string const &target) {
	if (isDead()) {
		std::cout << "ScavTrap : " << _name << " can't attack because he is dead" << std::endl;
	} else if (!hasEnergy()) {
		std::cout << "ScavTrap : " << _name << " can't attack because he doesn't have energy" << std::endl;
	} else {
		std::cout << "ScavTrap : " << _name << " attacks " << target << ", causing " << _dp << " points of damage!" << std::endl;
		_ep -= 1;
	}
}

void ScavTrap::guardGate() const {
	if (isDead())
		std::cout << "ScavTrap : " << _name << " can't guard the gate because he is dead" << std::endl;
	else
		std::cout << "ScavTrap : " << _name << " is now in guate keeper mode" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap : " << __PRETTY_FUNCTION__ << " : default destructor called" << std::endl;
}
