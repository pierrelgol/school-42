/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 08:07:44 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/21 08:07:45 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanB {
      private:
	std::string _name;
	Weapon     *_weapon;

      public:
	HumanB();
	HumanB(std::string const &name);
	void setWeapon(Weapon &weapon);
	void attack(void) const;
	~HumanB();
	// I hate this language
};

#endif // HUMANB_HPP
