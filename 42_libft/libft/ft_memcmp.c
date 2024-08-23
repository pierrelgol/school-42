/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:56:10 by pollivie          #+#    #+#             */
/*   Updated: 2023/10/02 11:56:12 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *ptr_s1;
	const unsigned char *ptr_s2;

	ptr_s1 = (unsigned char *)s1;
	ptr_s2 = (unsigned char *)s2;
	while(--n && *ptr_s1 == *ptr_s2)
	{
		++ptr_s1;
		++ptr_s2;
	}
	return (*ptr_s1 - *ptr_s2);
}