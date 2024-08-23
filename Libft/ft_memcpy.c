/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:50:57 by pollivie          #+#    #+#             */
/*   Updated: 2023/10/02 11:50:59 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	register const char	*ptr_src;
	register char		*ptr_dst;
	size_t				i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	ptr_dst = dst;
	ptr_src = src;
	while (i < n)
	{
		*ptr_dst++ = *ptr_src++;
		++i;
	}
	return (dst);
}
