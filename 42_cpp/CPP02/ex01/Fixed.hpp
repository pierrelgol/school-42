/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:10:24 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/21 12:10:25 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <cmath>
#include <iostream>

class Fixed {
      private:
	static int const _fractional_bits = 8;
	int              _fixed_point;

      public:
	Fixed(void);

	Fixed(int const value);
	Fixed(float const value);
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &rhs);
	int    getRawBits(void) const;
	void   setRawBits(int const raw);
	float  floatFromInt(void) const;
	int    intFromFloat(void) const;

	~Fixed(void);
};
// WTF???? (˚ ˃̣̣̥⌓˂̣̣̥ ) 🤮🤮🤮🤮🤮🤮🤮🤮🤮🤮🤮🤮🤮🤮🤮🤮🤮🤮🤮
std::ostream &operator<<(std::ostream &o, const Fixed &fixed);

#endif // FIXED_HPP
