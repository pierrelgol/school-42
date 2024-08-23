/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 07:21:31 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/21 07:21:31 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
}

Zombie::Zombie(std::string name) : _name(name) {
}

void Zombie::announce(int N, Zombie const *horde) const {
	for (int i = 0; i < N; i++) {
		std::cout << horde[i]._name << " : BraiiiiiinnnzzzZ" << std::endl;
	}
}

void Zombie::announce(void) const {
	std::cout << _name << " : BraiiiiiinnnzzzZ" << std::endl;
}

void Zombie::setName(std::string const &name) {
	this->_name = name;
}

Zombie::~Zombie() {
	std::cout << _name << " : destroyed" << std::endl;
}
