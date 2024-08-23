/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierreollivier <plgol.perso@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:39:05 by pierreollivie     #+#    #+#             */
/*   Updated: 2023/07/07 17:39:08 by pierreollivie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*ret;

	ret = NULL;
	while (*s)
	{
		if (*s == (unsigned char)c)
			ret = (char *)s;
		++s;
	}
	if (c == '\0')
	{
		while (*s)
			++s;
		return ((char *)s);
	}
	return (ret);
}

// char	*ft_strrchr(const char *s, int c)
// {
// 	register const char	*psrc;
// 	char				*ret;

// 	psrc = s;
// 	ret = NULL;
// 	while (*psrc && *(psrc + 1))
// 	{
// 		if (*psrc == (unsigned char)c)
// 			ret = (char *)psrc;
// 		if (*(psrc + 1) == (unsigned char)c)
// 			ret = (char *)(psrc + 1);
// 		psrc += 2;
// 	}
// 	while (*psrc)
// 	{
// 		if (*psrc == (unsigned char)c)
// 			ret = (char *)psrc;
// 		++psrc;
// 	}
// 	if (c == '\0')
// 		return ((char *)psrc);
// 	return (ret);
// }

// char *ft_strrchr(const char *s, int c)
// {
//   register const char *psrc;
//   char *ret;

//   psrc = s;
//   ret = NULL;
//   while ( *psrc )
//   {
//     if ( *psrc == (const unsigned char) c )
//       ret = (char*) psrc;
//     ++psrc;
//   }
//   if ( !c )
//     return ( (char*) psrc );
//   return ( ret );
// }

// char *ft_strrchr(const char *s, int c)
// {
//     char *ret = NULL;

//     if (c == '\0')
//     {
//         while (*s)
//             ++s;
//         return (char *)s;
//     }

//     while (*s)
//     {
//         if (*s == (unsigned char)c)
//             ret = (char *)s;
//         ++s;
//     }

//     return ret;
// }
