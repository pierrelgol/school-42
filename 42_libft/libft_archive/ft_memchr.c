/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierreollivier <plgol.perso@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:31:20 by pierreollivie     #+#    #+#             */
/*   Updated: 2023/07/07 12:31:25 by pierreollivie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	register const unsigned char	*psrc;
	register const unsigned char	*end;

	end = (const unsigned char *)s + n;
	psrc = (const unsigned char *)s;
	while ((psrc + 4) < end)
	{
		if (*psrc == (const unsigned char)c)
			return ((void *)(psrc));
		if (*(psrc + 1) == (const unsigned char)c)
			return ((void *)(psrc + 1));
		if (*(psrc + 2) == (const unsigned char)c)
			return ((void *)(psrc + 2));
		if (*(psrc + 3) == (const unsigned char)c)
			return ((void *)(psrc + 3));
		psrc += 4;
	}
	while (psrc < end)
	{
		if (*psrc == (const unsigned char)c)
			return ((void *)(psrc));
		++psrc;
	}
	return (NULL);
}

// void *ft_memchr(const void *s, int c, size_t n)
// {
//   register const unsigned char *psrc;
//   register const unsigned char *end;

//   end  = (const unsigned char *) s + n;
//   psrc = (const unsigned char *) s;
//   while ( psrc < end )
//   {
//     if ( *psrc == (const unsigned char) c )
//       return ( (void*) (psrc) );
//     ++psrc;
//   }
//   return ( NULL );
// }
