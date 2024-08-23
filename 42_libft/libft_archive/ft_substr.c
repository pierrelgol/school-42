/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierreollivier <plgol.perso@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:45:52 by pierreollivie     #+#    #+#             */
/*   Updated: 2023/07/07 17:45:55 by pierreollivie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, size_t start, size_t len)
{
	register const char	*pstr;
	register char		*ret;
	register size_t		i;

	pstr = s + start;
	if (!s)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	i = 0;
	if (ft_strlen(s) > start)
	{
		while ((len - i) && *(pstr + i))
		{
			*(ret + i) = *(pstr + i);
			i++;
		}
		ret[i] = '\0';
	}
	return (ret);
}
