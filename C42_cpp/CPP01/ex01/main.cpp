/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 07:19:23 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/21 07:19:24 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

#define NUMBER_OF_ZOMBIES 10

int main(void) {
	Zombie *horde = zombieHorde(NUMBER_OF_ZOMBIES, "The Worst Programming Language");
	horde->announce(NUMBER_OF_ZOMBIES, horde);
	// The fuck is that shit
	delete[] horde;
	return (0);
}
