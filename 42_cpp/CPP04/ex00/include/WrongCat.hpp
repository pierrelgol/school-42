/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 13:58:50 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/25 13:58:51 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>
#include <string>

class WrongCat : public WrongAnimal {
      public:
	WrongCat();
	WrongCat(std::string type);
	WrongCat(WrongCat const &other);
	WrongCat &operator=(WrongCat const &other);
	void      makeSound() const;
	~WrongCat();
};

#endif // WRONGCAT_HPP
