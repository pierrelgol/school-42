/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 07:19:50 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/21 07:19:51 by pollivie         ###   ########.fr       */
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
	void announce(int N, Zombie const *horde) const;
	void setName(std::string const &name);
	~Zombie();
};

Zombie *zombieHorde(int N, std::string name);

#endif // ZOMBIE_HPP
