/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:04:51 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/25 15:04:52 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <cstdlib>

Brain::Brain() {
	std::cout << "Brain : " << __PRETTY_FUNCTION__ << " default ctor called" << std::endl;

	const std::string ideas[] = {
	    "I need to go for a walk", "I need to sleep",        "I need to go to the vet", "I need to hunt",
	    "I need to be pet",        "I need to make a sound", "I need to drink",         "I need to eat",
	    "I need to poo",           "I need to hunt",         "I need to be pet",        "I need to make a sound",
	};

	for (int i = 0; i < IDEAS_MAX; ++i) {
		this->_ideas[i] = ideas[rand() % IDEAS_MAX];
	}
}

Brain::Brain(Brain const &other) {
	std::cout << "Brain : " << __PRETTY_FUNCTION__ << " copy ctor called" << std::endl;
	for (int i = 0; i < IDEAS_MAX; ++i) {
		this->_ideas[i] = other._ideas[i];
	}
}

Brain &Brain::operator=(Brain const &other) {
	std::cout << "Brain : " << __PRETTY_FUNCTION__ << " assignment ctor called" << std::endl;
	if (this != &other) {
		for (int i = 0; i < IDEAS_MAX; ++i) {
			this->_ideas[i] = other._ideas[i];
		}
	}
	return (*this);
}

Brain::~Brain() {
	std::cout << "Brain : " << __PRETTY_FUNCTION__ << " dtor called" << std::endl;
}
