/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierreollivier <plgol.perso@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:12:50 by pierreollivie     #+#    #+#             */
/*   Updated: 2023/07/07 17:13:45 by pierreollivie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	register const unsigned char	*psrc;
	register unsigned char			*pdst;

	psrc = (const unsigned char *)src;
	pdst = (unsigned char *)dst;
	if (dst == src)
		return (dst);
	if (psrc < pdst)
	{
		while (len--)
			*(pdst + len) = *(psrc + len);
		return (pdst);
	}
	while (len--)
		*pdst++ = *psrc++;
	return (pdst);
}
