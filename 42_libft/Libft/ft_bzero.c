/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:50:42 by pollivie          #+#    #+#             */
/*   Updated: 2023/10/02 11:50:43 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr_s;
	unsigned char	*ptr_end;

	ptr_s = (unsigned char *)s;
	ptr_end = (unsigned char *)s + n;
	while (ptr_s < ptr_end)
		*ptr_s++ = 0;
}
