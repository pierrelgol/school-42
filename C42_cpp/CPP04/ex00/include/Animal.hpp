/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:22:11 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/22 15:24:34 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
      protected:
	std::string type;

      public:
	Animal();
	Animal(Animal const &other);
	Animal &operator=(Animal const &other);
	void    makeSound();
	~Animal();
};

#endif // ANIMAL_HPP
