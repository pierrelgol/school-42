/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 10:54:29 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/25 10:54:30 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	split_size(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		++i;
	return (i);
}

int	square_root(int n)
{
	double	x;
	double	epsilon;

	x = n;
	epsilon = 0.000001;
	while ((x * x - n) > epsilon)
	{
		x = (x + n / x) / 2;
	}
	return ((int)x);
}
