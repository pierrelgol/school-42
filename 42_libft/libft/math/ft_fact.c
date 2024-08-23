/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fact.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:44:24 by pollivie          #+#    #+#             */
/*   Updated: 2023/10/17 13:44:25 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

long	ft_fact(long n)
{
	long	result;

	if (n <= 0)
		return (1);
	result = n;
	while (--n)
		result *= n;
	return (result);
}
