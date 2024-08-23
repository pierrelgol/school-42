/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierreollivier <plgol.perso@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:32:16 by pierreollivie     #+#    #+#             */
/*   Updated: 2023/07/07 17:32:19 by pierreollivie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	dlen;
	unsigned int	smax;
	unsigned int	i;

	if (dstsize == 0)
		return (0);

	dlen = ft_strlen(dst);
	smax = dstsize - dlen - 1;
	i = 0;
	while (i < smax && src[i])
	{
		dst[dlen + i] = src[i];
		++i;
	}
	dst[dlen + i] = '\0';
	return (dlen + i);
}
