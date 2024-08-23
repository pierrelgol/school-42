/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:39:39 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/21 10:39:40 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

typedef void (*log_fn)(void);

class Harl {
      private:
	static void no_op(void);
	static void debug(void);
	static void info(void);
	static void warning(void);
	static void error(void);

      public:
	enum { DEBUG, INFO, WARNING, ERROR };
	Harl();
	void complain(std::string level) const;
	int  toInt(std::string const &level) const;
	~Harl();
};

#endif // HARL_HPP
