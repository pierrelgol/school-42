/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 08:07:50 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/21 08:07:51 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// fuck is that fucking language
HumanA::HumanA(std::string const &name, Weapon &weapon) : _name(name), _weapon(weapon) {
}

// trash language
void HumanA::attack(void) const {
	std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
}

// what is happening ??? why is this language so bad I swear it's a fucking joke
HumanA::~HumanA() {
}
