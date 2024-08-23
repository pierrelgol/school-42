/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:54:51 by pollivie          #+#    #+#             */
/*   Updated: 2023/10/02 12:54:52 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr_end;
	const unsigned char	*ptr_s;

	ptr_end = (unsigned char *)s + n;
	ptr_s = (unsigned char *)s;
	while (ptr_s < ptr_end && *ptr_s != (unsigned char)c)
		++ptr_s;
	if (ptr_s == ptr_end)
		return (NULL);
	return ((void *)ptr_s);
}
