/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierreollivier <plgol.perso@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:34:27 by pierreollivie     #+#    #+#             */
/*   Updated: 2023/07/07 17:34:31 by pierreollivie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlen(const char *s)
{
	register const unsigned char	*ps;

	ps = (const unsigned char *)s;
	while (*(ps) && *(ps + 1) && *(ps + 2) && *(ps + 3))
		ps += 4;
	while (*(ps))
		++ps;
	return (ps - (const unsigned char *)s);
}
