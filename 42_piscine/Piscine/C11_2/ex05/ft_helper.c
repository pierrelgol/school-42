/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:24:11 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/25 13:24:13 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	do_putnbrecurs(long nb)
{
	if (nb == 0)
		return ;
	do_putnbrecurs(nb / 10);
	write(1, &"0123456789"[nb % 10], 1);
}

void	do_putstr(char *str)
{
	int	slen;

	slen = 0;
	while (str[slen])
		++slen;
	write(1, str, slen);
}

void	do_putnbr(int nbr)
{
	long	nb;

	nb = nbr;
	if (nb <= 0)
	{
		if (nb == 0)
		{
			write(1, "0", 1);
			return ;
		}
		else
		{
			nb *= -1;
			write(1, "-", 1);
		}
	}
	do_putnbrecurs(nb);
	write(1, "\n", 1);
}

int	do_atoi(char *nbr)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*nbr && (*nbr == ' ' || (*nbr >= 9 && *nbr <= 13)))
		++nbr;
	while (*nbr && (*nbr == '-' || *nbr == '+'))
		if (*nbr++ == '-')
			sign *= -1;
	while (*nbr && (*nbr >= '0' && *nbr <= '9'))
		res = (*nbr++ - '0') + (res * 10);
	return (res * sign);
}

int	do_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		++s1;
		++s2;
	}
	return (*s1 - *s2);
}
