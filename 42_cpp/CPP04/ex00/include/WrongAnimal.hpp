/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 13:48:54 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/25 13:48:55 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {
      protected:
	std::string _type;

      public:
	WrongAnimal();
	WrongAnimal(WrongAnimal const &other);
	WrongAnimal(std::string type);
	WrongAnimal &operator=(WrongAnimal const &other);
	virtual void makeSound() const;
	std::string  getType() const;

	virtual ~WrongAnimal();
};

#endif // WRONGANIMAL_HPP
