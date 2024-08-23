/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierreollivier <plgol.perso@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:38:01 by pierreollivie     #+#    #+#             */
/*   Updated: 2023/07/07 17:38:06 by pierreollivie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	register const char	*phay;
	register const char	*pned;

	if (*needle == '\0' || len == 0)
		return ((char *)haystack);
	phay = haystack;
	while (*phay && phay < (haystack + len))
	{
		pned = needle;
		while (*pned && *phay == *pned)
		{
			if (*(pned + 1) == '\0' && *phay == *pned)
				return ((char *)phay);
			++pned;
		}
		++phay;
	}
	return (NULL);
}
