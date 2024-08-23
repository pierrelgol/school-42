/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierreollivier <plgol.perso@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 18:13:53 by pierreollivie     #+#    #+#             */
/*   Updated: 2023/07/09 18:14:01 by pierreollivie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static inline int	ft_isspace(int n)
{
	if (n == ' ' || n == '\t' || n == '\n')
		return (1);
	if (n == '\r' || n == '\f' || n == '\v')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		++str;
	}
	return (sign * result);
}
