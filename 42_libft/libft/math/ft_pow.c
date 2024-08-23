/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:45:27 by pollivie          #+#    #+#             */
/*   Updated: 2023/10/17 13:45:28 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

long	ft_pow(long n, long pow)
{
	long	result;

	if (pow < 0)
		return (0);
	if (pow == 0)
		return (1);
	result = n;
	while (--pow)
		result *= n;
	return (result);
}
