/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 12:20:34 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/22 12:20:35 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main(void) {
	{
		std::cout << "Test : 0" << std::endl;
		std::cout << "----------------------------------------" << std::endl;
		ClapTrap a = ClapTrap("foo");
		ClapTrap b = ClapTrap("bar");

		a.attack("bar");
		b.takeDamage(0);

		b.attack("foo");
		a.takeDamage(0);
	}

	{
		std::cout << "----------------------------------------" << std::endl;
		std::cout << "Test : 1" << std::endl;
		std::cout << "----------------------------------------" << std::endl;
		ClapTrap a = ClapTrap("foo");
		ClapTrap b;

		b = a;
		b.beRepaired(0);
	}

	{
		std::cout << "----------------------------------------" << std::endl;
		std::cout << "Test : 2" << std::endl;
		std::cout << "----------------------------------------" << std::endl;
		ClapTrap a;
		ClapTrap b(a);

		b.beRepaired(0);
		std::cout << "----------------------------------------" << std::endl;
	}

	return (0);
}
