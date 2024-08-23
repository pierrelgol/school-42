/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atan.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:42:57 by pollivie          #+#    #+#             */
/*   Updated: 2023/10/17 13:42:58 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

float	ft_atan(float x)
{
	float	sum;
	float	temp;
	int		n;

	n = 0;
	sum = 0.0;
	while (n < STEPS)
	{
		temp = ft_powf(-1, n) * ft_powf(x, 2 * n + 1) / (2 * n + 1);
		sum += temp;
		++n;
	}
	return (sum);
}
