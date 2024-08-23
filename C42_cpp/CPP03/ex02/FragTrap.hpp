/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:37:36 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/22 14:37:37 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

// Why this exercice exist like seriously It took 3 minutes to complete!
// what was the purpose ? to learn how to do ctrl+c / ctrl+v and rename
// every ScavTrap to FragTrap ? what's the point of waisting my time
// on such useless trash ???
class FragTrap : public ClapTrap {
      private:
      public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(FragTrap const &other);
	FragTrap &operator=(FragTrap const &other);
	void      attack(std::string const &target);
	void      highFivesGuys() const;
	~FragTrap();
};

#endif // FRAGTRAP_HPP
