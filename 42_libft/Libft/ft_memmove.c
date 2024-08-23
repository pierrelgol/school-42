/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:51:13 by pollivie          #+#    #+#             */
/*   Updated: 2023/10/02 11:51:15 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*ptr_src;
	char		*ptr_dst;

	ptr_src = (const char *)src;
	ptr_dst = (char *)dst;
	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		while (len)
		{
			*(ptr_dst + len - 1) = *(ptr_src + len - 1);
			len--;
		}
		return (dst);
	}
	while (len--)
		*ptr_dst++ = *ptr_src++;
	return (dst);
}
