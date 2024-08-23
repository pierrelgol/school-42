/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:56:33 by pollivie          #+#    #+#             */
/*   Updated: 2023/10/02 11:56:35 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (!count || !size)
		return (malloc(0));
	if (count > INT_MAX / size)
		return (NULL);
	ptr = malloc(size * count);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, (count * size));
	return (ptr);
}
