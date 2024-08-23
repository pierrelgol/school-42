/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierreollivier <plgol.perso@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:12:04 by pierreollivie     #+#    #+#             */
/*   Updated: 2023/07/07 17:12:09 by pierreollivie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	register const char	*psrc;
	register char		*pdst;
	const char			*end;

	if (!dst && !src)
		return (NULL);
	end = (const char *)src + n;
	psrc = (const char *)src;
	pdst = (char *)dst;
	while ((psrc + 8) <= end)
	{
		*(pdst) = *(psrc);
		*(pdst + 1) = *(psrc + 1);
		*(pdst + 2) = *(psrc + 2);
		*(pdst + 3) = *(psrc + 3);
		*(pdst + 4) = *(psrc + 4);
		*(pdst + 5) = *(psrc + 5);
		*(pdst + 6) = *(psrc + 6);
		*(pdst + 7) = *(psrc + 7);
		pdst += 8;
		psrc += 8;
	}
	while (psrc < end)
		*(pdst++) = *(psrc++);
	return (dst);
}
