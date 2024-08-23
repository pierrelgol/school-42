/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:11:48 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/21 11:11:49 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iomanip>
#include <iostream>

/*
  ^ will to live
  |\
  | \
  |  \
  |   \
  |    \
  |     \
  |      \
  |       \
  |        \
  |         \
  |          \
  |           \
 -|------------\------------------------------------------------------------>
 0|             \                                     time programming in C++
*/

int main(void) {
	Fixed a;
	Fixed b(a);
	Fixed c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return (0);
}
