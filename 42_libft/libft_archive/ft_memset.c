/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierreollivier <plgol.perso@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:15:29 by pierreollivie     #+#    #+#             */
/*   Updated: 2023/07/07 17:15:32 by pierreollivie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	register unsigned char			*itterator;
	register const unsigned char	*end;

	end = (const unsigned char *)b + len;
	itterator = (unsigned char *)b;
	while ((itterator + 4) < end)
	{
		*(itterator) = (const unsigned char)c;
		*(itterator + 1) = (const unsigned char)c;
		*(itterator + 2) = (const unsigned char)c;
		*(itterator + 3) = (const unsigned char)c;
		itterator += 4;
	}
	while (itterator < end)
		*itterator++ = (const unsigned char)c;
	return (b);
}
