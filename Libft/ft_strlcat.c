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

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	if ((!dst || !src) && !size)
		return (0);
	k = 0;
	i = ft_strlen(dst);
	j = ft_strlen(src);
	if (!size)
		return (j);
	k = j + i;
	if (i > size)
		return (j + size);
	j = 0;
	while (src[j] && i + j < size - 1)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	if (k >= i + size && i > k - i)
		return (i + size);
	return (k);
}
