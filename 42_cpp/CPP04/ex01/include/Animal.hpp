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

#include <iostream>
#include <string>

class Animal {
      protected:
	std::string _type;

      public:
	Animal();
	Animal(Animal const &other);
	Animal(std::string type);
	Animal      &operator=(Animal const &other);
	virtual void makeSound() const;
	std::string  getType() const;

	virtual ~Animal();
};

#endif // ANIMAL_HPP
