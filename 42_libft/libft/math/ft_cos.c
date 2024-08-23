/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:44:09 by pollivie          #+#    #+#             */
/*   Updated: 2023/10/17 13:44:10 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

float	ft_cos(float x)
{
	float	sum;
	float	temp;
	int		n;

	n = 0;
	sum = 0.0;
	while (n < STEPS)
	{
		temp = ft_pow(-1, n) * ft_powf(x, 2 * n);
		temp /= ft_fact(2 * n);
		sum += temp;
		++n;
	}
	return (sum);
}
