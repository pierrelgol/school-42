/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierreollivier <plgol.perso@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:55:18 by pierreollivie     #+#    #+#             */
/*   Updated: 2023/07/07 11:55:25 by pierreollivie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_intlen(long n)
{
	if (n == 0)
		return (0);
	return (1 + ft_intlen(n / 10));
}

static int	ft_itoa_recur(char *s, long n, int i)
{
	if (n == 0)
		return (0);
	s[--i] = '0' + (n % 10);
	n /= 10;
	return (ft_itoa_recur(s, n, i));
}

char	*ft_itoa(int n)
{
	char			*ret;
	long			nl;
	unsigned int	nlen;
	unsigned int	is_neg_or_zero;

	nl = n;
	is_neg_or_zero = 0;
	if (nl <= 0)
	{
		is_neg_or_zero = 1;
		nl *= -1;
	}
	nlen = ft_intlen(nl);
	ret = (char *)malloc(sizeof(char) * (nlen + 1 + is_neg_or_zero));
	if (ret == NULL)
		return (NULL);
	if (is_neg_or_zero)
		ret[0] = '-';
	if (n == 0)
		*ret = '0';
	else
		(void)ft_itoa_recur(&ret[is_neg_or_zero], nl, nlen);
	ret[nlen + is_neg_or_zero] = '\0';
	return (ret);
}
