/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierreollivier <plgol.perso@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:36:08 by pierreollivie     #+#    #+#             */
/*   Updated: 2023/07/07 17:36:16 by pierreollivie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	register const unsigned char	*ps1;
	register const unsigned char	*ps2;
	const unsigned char				*end;

	ps1 = (const unsigned char *)s1;
	ps2 = (const unsigned char *)s2;
	end = (const unsigned char *)s1 + n - 1;
	while (*ps1 && ps1 < end && *ps1 == *ps2)
	{
		++ps1;
		++ps2;
	}
	return (*ps1 - *ps2);
}
