/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 13:46:44 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/25 13:46:44 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

class Cat : public Animal {
      private:
	Brain *_brain;

      public:
	Cat();
	Cat(std::string type);
	Cat(Cat const &other);
	Cat   &operator=(Cat const &other);
	void   makeSound() const;
	Brain *getBrain() const;
	~Cat();
};

#endif // CAT_HPP
