/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:20:04 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/19 11:20:14 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int		ft_parse_base(char *base);
int		ft_base_at(char ch, char *base);
int		ft_atoi_base(char *nbr, char *base);

int	ft_intlen(long nbr, int radix)
{
	if (nbr == 0)
		return (0);
	return (1 + ft_intlen(nbr / radix, radix));
}

void	ft_putnbr_base(long nbr, short radix, char *base, char *result)
{
	if (nbr == 0)
		return ;
	*(--result) = base[nbr % radix];
	ft_putnbr_base(nbr / radix, radix, base, result);
}

void	ft_init_sign(char *result, long nbr, short sign, char *base)
{
	if (nbr == 0 || sign == 1)
	{
		if (sign == 1)
			result[0] = '-';
		if (nbr == 0)
		{
			result[0] = base[0];
			result[1] = '\0';
		}
	}
}

char	*ft_itoa_base(long nbr, char *base)
{
	char	*result;
	short	sign;
	short	radix;
	short	length;

	radix = ft_parse_base(base);
	sign = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		sign = 1;
	}
	length = ft_intlen(nbr, radix) + (!(nbr & ~0)) + sign;
	result = (char *)malloc(sizeof(char) * (length + 1));
	if (!result)
		return (NULL);
	ft_init_sign(result, nbr, sign);
	ft_putnbr_base(nbr, radix, base, &result[ft_intlen(nbr, radix) + sign]);
	result[ft_intlen(nbr, radix) + sign + (!(nbr & ~0))] = '\0';
	return (result);
}
