/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 13:35:19 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/25 13:35:20 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

class Dog : public Animal {
      private:
	Brain *_brain;

      public:
	Dog();
	Dog(std::string type);
	Dog(Dog const &other);
	Dog   &operator=(Dog const &other);
	void   makeSound() const;
	Brain *getBrain() const;
	~Dog();
};

#endif // DOG_HPP
