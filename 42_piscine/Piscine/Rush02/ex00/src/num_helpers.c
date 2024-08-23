/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bissenma <bissenma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:52:47 by bissenma          #+#    #+#             */
/*   Updated: 2023/09/24 15:53:32 by bissenma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/num_helpers.h"

int	helpers_atoi(char *str)
{
	int	i;
	int	number;
	int	sign;

	i = 0;
	number = 0;
	sign = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign++;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		number = number * 10 + (str[i] - 48);
		i++;
	}
	if (sign % 2 == 1)
	{
		write(-1, "Error\n", 6);
		return (0);
	}
	return (number);
}

int	helpers_strlen(char *str)
{
	int	slen;

	if (!str)
		return (0);
	slen = 0;
	while (str[slen])
		++slen;
	return (slen);
}

int	helpers_is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}

int	helpers_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
