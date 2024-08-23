/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 07:21:36 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/21 07:21:37 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name) {
	Zombie *horde = (N > 0) ? new Zombie[N]() : NULL;
	for (int i = 0; i < N; i++)
		horde[i].setName(name);
	return (horde);
}
