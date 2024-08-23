/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierreollivier <plgol.perso@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:26:48 by pierreollivie     #+#    #+#             */
/*   Updated: 2023/07/07 17:26:52 by pierreollivie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	register const char	*psrc;

	psrc = s;
	while (*(psrc) && *(psrc + 1) && *(psrc + 2) && *(psrc + 3))
	{
		if (*psrc == (const unsigned char)c)
			return ((char *)psrc);
		if (*(psrc + 1) == (const unsigned char)c)
			return ((char *)(psrc + 1));
		if (*(psrc + 2) == (const unsigned char)c)
			return ((char *)(psrc + 2));
		if (*(psrc + 3) == (const unsigned char)c)
			return ((char *)(psrc + 3));
		psrc += 4;
	}
	while (*(psrc))
	{
		if (*psrc == (const unsigned char)c)
			return ((char *)psrc);
		++psrc;
	}
	if (!c)
		return ((char *)psrc);
	return ((char *)(NULL));
}
