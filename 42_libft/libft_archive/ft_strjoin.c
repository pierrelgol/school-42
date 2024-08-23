/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierreollivier <plgol.perso@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:31:01 by pierreollivie     #+#    #+#             */
/*   Updated: 2023/07/07 17:31:12 by pierreollivie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	register unsigned int	i;
	register char			*ret;
	unsigned int			sl1;
	unsigned int			sl2;

	sl1 = ft_strlen(s1);
	sl2 = ft_strlen(s2);
	ret = (char *)malloc(sizeof(char) * (sl1 + sl2 + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (i <= (sl1 + sl2))
	{
		if (i < sl1)
			*(ret + i) = *(s1 + i);
		if (i >= sl1)
			*(ret + i) = *(s2 + (i - sl1));
		++i;
	}
	*(ret + i + 1) = '\0';
	return (ret);
}
