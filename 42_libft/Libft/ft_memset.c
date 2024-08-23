/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:50:32 by pollivie          #+#    #+#             */
/*   Updated: 2023/10/02 11:50:33 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	register unsigned char	*ptr_b;
	register unsigned char	*ptr_end;

	ptr_b = (unsigned char *)b;
	ptr_end = (unsigned char *)b + len;
	while (ptr_b < ptr_end)
		*ptr_b++ = (unsigned char)c;
	return (b);
}
