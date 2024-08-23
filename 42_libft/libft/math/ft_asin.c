/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:42:36 by pollivie          #+#    #+#             */
/*   Updated: 2023/10/17 13:42:40 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

float	ft_asin(float x)
{
	float	sum;
	float	temp;
	int		n;

	n = 0;
	sum = 0.0;
	while (n < STEPS)
	{
		temp = ft_factf(2 * n);
		temp /= (ft_powf(4, n) * ft_powf(ft_factf(n), 2) * (2 * n + 1))
			* ft_powf(x, 2 * n + 1);
		sum += temp;
		++n;
	}
	return (sum);
}
