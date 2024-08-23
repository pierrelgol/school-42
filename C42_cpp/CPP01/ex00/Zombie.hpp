/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 06:59:33 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/21 06:59:33 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
      private:
	std::string _name;

      public:
	Zombie();
	Zombie(std::string name);
	void announce(void) const;
	~Zombie();
};

Zombie *newZombie(std::string name);
void    randomChump(std::string name);

#endif // ZOMBIE_HPP
