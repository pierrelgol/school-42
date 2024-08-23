/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierreollivier <plgol.perso@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:49:32 by pierreollivie     #+#    #+#             */
/*   Updated: 2023/07/07 11:49:41 by pierreollivie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *b, size_t n)
{
	unsigned register char			*itterator;
	const unsigned register char	*end;

	itterator = (unsigned char *)b;
	end = (const unsigned char *)b + n;
	while ((itterator + 8) < end)
	{
		*(itterator) = '\0';
		*(itterator + 1) = '\0';
		*(itterator + 2) = '\0';
		*(itterator + 3) = '\0';
		*(itterator + 4) = '\0';
		*(itterator + 5) = '\0';
		*(itterator + 6) = '\0';
		*(itterator + 7) = '\0';
		itterator += 8;
	}
	while (itterator < end)
		*itterator++ = '\0';
}
