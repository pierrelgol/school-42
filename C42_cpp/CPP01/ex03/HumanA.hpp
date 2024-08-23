/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 08:07:39 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/21 08:07:40 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

// Absolute dogshit
class HumanA {
      private:
	std::string _name;
	Weapon     &_weapon;

      public:
	HumanA();
	HumanA(std::string const &name, Weapon &weapon);
	void attack(void) const;
	~HumanA();
};

#endif // HUMANA_HPP
