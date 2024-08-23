/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 05:40:32 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/21 05:40:33 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main() {
	Zombie foo = Zombie("foo");
	foo.announce();

	Zombie *bar = newZombie("bar");
	bar->announce();

	// ho look I'm not using free like a fucking grown up. Instead I use
	// delete just because nobody loves me and I want to be fucking different
	// in life. Cunty C++
	delete bar;
	return (0);
}
