/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:58:04 by pollivie          #+#    #+#             */
/*   Updated: 2023/10/02 11:58:05 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nlen(int nbr)
{
	if (nbr == 0)
		return (0);
	return (1 + ft_nlen(nbr / 10));
}

static void	ft_putitoa(char *result, long nb, size_t i)
{
	if (nb == 0)
		return ;
	result[--i] = nb % 10 + '0';
	ft_putitoa(result, nb / 10, i);
}

char	*ft_itoa(int nbr)
{
	char	*result;
	long	nb;
	int		neg_or_zero;
	int		rlen;

	nb = nbr;
	rlen = 0;
	neg_or_zero = 0;
	if (nb <= 0)
	{
		neg_or_zero = 1;
		nb *= -1;
	}
	rlen += ft_nlen(nb);
	result = (char *)ft_calloc(rlen + neg_or_zero + 1, sizeof(char));
	if (!result)
		return (NULL);
	if (neg_or_zero == 1)
		result[0] = '-';
	if (nb == 0)
		result[0] = '0';
	ft_putitoa(&result[neg_or_zero], nb, rlen);
	return (result);
}
