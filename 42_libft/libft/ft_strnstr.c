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
#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*ptr_hay;
	const char	*ptr_nee;

	if (*needle == '\0' || len == 0)
		return ((char *)haystack);
	ptr_hay = haystack;
	while (*ptr_hay && ptr_hay < (haystack + len))
	{
		ptr_nee = needle;
		while (*ptr_nee && *ptr_nee == *ptr_hay)
		{
			if (*(ptr_nee + 1) == '\0')
				return ((char *)ptr_hay);
			++ptr_nee;
		}
		++ptr_hay;
	}
	return (NULL);
}