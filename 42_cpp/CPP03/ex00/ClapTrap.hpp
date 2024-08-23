/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 12:20:46 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/22 12:20:46 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
      private:
	std::string  _name;
	unsigned int _hp;
	unsigned int _ep;
	unsigned int _dp;

      public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const &other);
	ClapTrap &operator=(ClapTrap const &other);
	bool      isDead() const;
	bool      hasEnergy() const;
	void      attack(const std::string &target);
	void      takeDamage(unsigned int amount);
	void      beRepaired(unsigned int amount);
	~ClapTrap();
};

#endif // CLAPTRAP_HPP
