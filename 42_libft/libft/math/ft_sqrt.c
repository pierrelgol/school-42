/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:45:50 by pollivie          #+#    #+#             */
/*   Updated: 2023/10/17 13:45:51 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

double	ft_sqrt(double n)
{
	double	guess;

	if (n <= 0)
		return (0);
	guess = n * 0.5;
	while (ft_absf(guess * guess) - n > EPSILON)
	{
		guess = 0.5 * (guess + n / guess);
	}
	return (guess);
}
