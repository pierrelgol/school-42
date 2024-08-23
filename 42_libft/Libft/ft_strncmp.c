/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:54:56 by pollivie          #+#    #+#             */
/*   Updated: 2023/10/02 11:54:58 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const char	*ptr_s1;
	const char	*ptr_s2;

	ptr_s1 = s1;
	ptr_s2 = s2;
	if (n == 0)
		return (0);
	while (--n && *ptr_s1 && *ptr_s1 == *ptr_s2)
	{
		++ptr_s1;
		++ptr_s2;
	}
	return ((unsigned char)*ptr_s1 - *ptr_s2);
}
