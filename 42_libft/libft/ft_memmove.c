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
	register const unsigned char	*ptr_src;
	register unsigned char		*ptr_dst;

	ptr_src = (const unsigned char *)src;
	ptr_dst = (unsigned char *)dst;
	if (dst == src)
		return (dst);
	if (ptr_src < ptr_dst)
	{
		while (len--)
			*(ptr_dst + len) = *(ptr_src + len);
		return (ptr_dst);
	}
	while (len--)
		*ptr_dst++ = *ptr_src++;
	return (ptr_dst);
}
