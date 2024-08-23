/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:45:43 by pollivie          #+#    #+#             */
/*   Updated: 2023/10/17 13:45:44 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

float	ft_sin(float x)
{
	float	sum;
	float	temp;
	int		n;

	n = 0;
	sum = 0.0;
	while (n < STEPS)
	{
		temp = ft_pow(-1, n) * ft_pow(x, 2 * n + 1);
		temp /= ft_fact(2 * n + 1);
		sum += temp;
		++n;
	}
	return (sum);
}
