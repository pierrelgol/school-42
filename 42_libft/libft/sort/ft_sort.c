/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:56:44 by pollivie          #+#    #+#             */
/*   Updated: 2023/10/17 14:56:45 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void ft_sort(void *data, size_t nel, size_t width, int (*compare)(const void *, const void *))
{
	char *start;
	char *end;
	char *ptr;
	char *buffer;

	start = (char *) data;
	end = (char *) data + (nel * width);
	buffer = (char *) alloca(sizeof(char) * width);
	ptr = (char *) data + width;
	while (ptr < end)
	{
		while (ptr >= start + width && compare((ptr - width), ptr) > 0)
		{
			ft_memcpy(buffer, ptr, width);
			ft_memcpy(ptr, (ptr - width), width);
			ft_memcpy((ptr - width), buffer, width);
			ptr -= width;
		}
		ptr += width;
	}
}
