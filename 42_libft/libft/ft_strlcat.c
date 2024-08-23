/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:51:36 by pollivie          #+#    #+#             */
/*   Updated: 2023/10/02 11:54:17 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	slen;
	size_t	dlen;
	size_t	i;

	if (dstsize == 0)
		return (ft_strlen(src));
	slen = -1;
	dlen = -1;
	while (src[++slen]);
	while (dst[++dlen]);
	if (dstsize <= dlen)
		return (dstsize + slen);
	i = dlen;
	while (src[i - dlen] != '\0' && (i + 1) < dstsize)
	{
		dst[i] = src[i - dlen];
		++i;
	}
	dst[i] = '\0';
	return(dlen + slen);
}