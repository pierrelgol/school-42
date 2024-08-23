/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:37:43 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/22 14:37:44 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	std::cout << "FragTrap : " << __PRETTY_FUNCTION__ << " : default constructor called" << std::endl;
	this->_hp = 100;
	this->_ep = 100;
	this->_dp = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "FragTrap : " << __PRETTY_FUNCTION__ << " : custom constructor called" << std::endl;
	this->_hp = 100;
	this->_ep = 50;
	this->_dp = 20;
}

FragTrap::FragTrap(FragTrap const &other) : ClapTrap(other) {
	std::cout << "FragTrap : " << __PRETTY_FUNCTION__ << " : copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &other) {
	std::cout << "FragTrap : " << __PRETTY_FUNCTION__ << " : assignment constructor called" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return (*this);
}

void FragTrap::attack(std::string const &target) {
	if (isDead()) {
		std::cout << "FragTrap : " << _name << " can't attack because he is dead" << std::endl;
	} else if (!hasEnergy()) {
		std::cout << "FragTrap : " << _name << " can't attack because he doesn't have energy" << std::endl;
	} else {
		std::cout << "FragTrap : " << _name << " attacks " << target << ", causing " << _dp << " points of damage!" << std::endl;
		_ep -= 1;
	}
}

void FragTrap::highFivesGuys() const {
	if (isDead())
		std::cout << "FragTrap : " << _name << " can't highFives because he is dead" << std::endl;
	else
		std::cout << "FragTrap : " << _name << " High five !!!!!!?" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap : " << __PRETTY_FUNCTION__ << " : default destructor called" << std::endl;
}
