/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierreollivier <plgol.perso@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:41:35 by pierreollivie     #+#    #+#             */
/*   Updated: 2023/07/07 17:44:11 by pierreollivie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_ch_in_set(const char ch, const char *set)
{
	const char	*pset;

	pset = set;
	while (*pset)
		if (*pset++ == ch)
			return (1);
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	const char	*ps1;
	size_t		start;
	size_t		end;
	size_t		i;
	char		*ret;

	ps1 = s1;
	end = ft_strlen(s1);
	start = 0;
	while (ps1[start] && ft_ch_in_set(ps1[start], set))
		start++;
	while (start < end && ft_ch_in_set(ps1[end - 1], set))
		end--;
	ret = (char *)malloc(sizeof(char) * (end - start + 1));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (start < end)
		ret[i++] = ps1[start++];
	ret[i] = '\0';
	return (ret);
}
