/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:51:28 by pollivie          #+#    #+#             */
/*   Updated: 2023/10/02 11:51:29 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	slen;
	size_t	i;

	i = 0;
	slen = 0;
	while (src[slen])
		++slen;
	if (dstsize == 0)
		return (slen);
	while (src[i] && (i + 1) < dstsize)
	{
		dst[i] = src[i];
		++i;
	}
	dst[i] = '\0';
	return (slen);
}
