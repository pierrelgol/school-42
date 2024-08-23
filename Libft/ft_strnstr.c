/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:55:59 by pollivie          #+#    #+#             */
/*   Updated: 2023/10/02 11:56:00 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	t_u32	u1;
	t_u32	u2;

	if (!haystack && len == 0)
		return (NULL);
	if (!*needle)
		return ((char *)haystack);
	u1 = 0;
	while (haystack[u1])
	{
		u2 = 0;
		while (haystack[u1] && haystack[u1] == needle[u2] && u1 < len)
		{
			u2++;
			u1++;
		}
		if (!needle[u2])
			return ((char *)&haystack[(int)u1 - u2]);
		u1 = (u1 - u2) + 1;
	}
	return (NULL);
}
