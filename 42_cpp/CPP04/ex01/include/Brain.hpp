/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 14:43:25 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/25 14:43:25 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

#define IDEAS_MAX 100

class Brain {
      private:
	std::string _ideas[IDEAS_MAX];

      public:
	Brain();
	Brain(Brain const &other);
	Brain             &operator=(Brain const &other);
	std::string const &getIdea(int index) const;
	~Brain();
};

#endif // BRAIN_HPP
