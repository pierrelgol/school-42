/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierreollivier <plgol.perso@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:33:48 by pierreollivie     #+#    #+#             */
/*   Updated: 2023/07/07 17:34:01 by pierreollivie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	register const char	*psrc;
	register char		*pdst;
	const char			*end;

	if (dstsize == 0)
		return (ft_strlen(src));
	psrc = src;
	pdst = dst;
	end = dst + (dstsize - 1);
	while (*psrc && (pdst + 4) < end)
	{
		*(pdst) = *(psrc);
		*(pdst + 1) = *(psrc + 1);
		*(pdst + 2) = *(psrc + 2);
		*(pdst + 3) = *(psrc + 3);
		pdst += 4;
		psrc += 4;
	}
	while (pdst < end && *psrc)
		*pdst++ = *psrc++;
	*pdst = '\0';
	return (ft_strlen(src));
}

// size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
// {
//   const register char *psrc = src;
//   const register char *end = dst + dstsize - 1;
//   register char *pdst;
//   size_t slen;

//   pdst = dst;
//   slen = 0;
//   while ( *psrc )
//   {
//     slen++;
//     psrc++;
//   }

//   if ( dstsize == 0)
//     return ( slen );
//   psrc = src;

//   while ( pdst < end && *psrc )
//     *pdst++ = *psrc++;

//   *pdst = '\0';
//   return ( slen );
// }
