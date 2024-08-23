/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierreollivier <plgol.perso@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:29:06 by pierreollivie     #+#    #+#             */
/*   Updated: 2023/07/07 17:29:11 by pierreollivie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	register unsigned int	dlen;
	register char			*dup;

	dlen = ft_strlen(s1);
	dup = (char *)malloc(sizeof(char) * (dlen + 1));
	if (!dup)
		return (NULL);
	dup = ft_memcpy(dup, s1, dlen + 1);
	return (dup);
}
