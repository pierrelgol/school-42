/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 08:07:28 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/21 08:07:28 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon {
      private:
	std::string _type;

      public:
	Weapon(void);
	Weapon(std::string const &type);
	Weapon(const Weapon &other);

	std::string const &getType(void) const;
	void               setType(std::string const &type);
	~Weapon();
};

#endif // WEAPON_HPP
