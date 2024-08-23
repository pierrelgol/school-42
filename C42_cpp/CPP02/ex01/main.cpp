/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:15:35 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/21 12:15:35 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main(void) {
	Fixed       a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed       d(b);

	a = Fixed(1234.4321f);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.intFromFloat() << " as integer" << std::endl;
	std::cout << "b is " << b.intFromFloat() << " as integer" << std::endl;
	std::cout << "c is " << c.intFromFloat() << " as integer" << std::endl;
	std::cout << "d is " << d.intFromFloat() << " as integer" << std::endl;

	return (0);
}
