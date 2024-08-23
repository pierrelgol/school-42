/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierreollivier <plgol.perso@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:20:11 by pierreollivie     #+#    #+#             */
/*   Updated: 2023/07/07 17:20:15 by pierreollivie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static inline unsigned int	ft_abs(int c)
{
	if (c < 0)
		return (-c);
	return (c);
}

void	ft_putnbr_fd(int n, int fd)
{
	char			ret[13];
	unsigned int	is_neg;
	register int	i;

	is_neg = (n < 0);
	ft_bzero(ret, 13);
	if (n == 0)
		ret[0] = '0';
	i = 0;
	while (n != 0)
	{
		ret[i++] = '0' + (ft_abs(n) % 10);
		n = (n / 10);
	}
	if (is_neg)
		ret[i] = '-';
	else if (i > 0)
		i--;
	while (i >= 0)
		write(fd, &ret[i--], 1);
}
