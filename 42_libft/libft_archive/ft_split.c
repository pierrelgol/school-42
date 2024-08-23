/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierreollivier <plgol.perso@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:25:16 by pierreollivie     #+#    #+#             */
/*   Updated: 2023/07/07 17:25:20 by pierreollivie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_count_word(const char *s, char c)
{
	const char	*ps;
	size_t		word;

	ps = s;
	word = 0;
	while (*ps)
	{
		while (*ps && *ps == c)
			ps++;
		if (*ps != '\0')
			word++;
		while (*ps && *ps != c)
			ps++;
	}
	return (word);
}

static unsigned int	ft_wlen(const char *s, char c)
{
	int	len;

	len = 0;
	while (*(s + len) && *(s + len) != c)
		len++;
	return (len);
}

static char	*ft_get_a_split(const char *s, char c)
{
	unsigned int	wlen;
	unsigned int	i;
	char			*ret;

	wlen = (ft_wlen(s, c));
	ret = (char *)malloc(sizeof(char) * (wlen + 1));
	if (!ret)
		return (0);
	i = 0;
	while (*(s + i) && i < wlen)
	{
		*(ret + i) = *(s + i);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	**ft_split(const char *s, char c)
{
	char	**ret;
	size_t	wcount;
	size_t	i;
	size_t	offset;

	wcount = ft_count_word(s, c);
	ret = (char **)malloc(sizeof(char *) * (wcount));
	if (!ret)
		return (NULL);
	i = 0;
	offset = 0;
	while (i < wcount)
	{
		while (*(s + offset) == c)
			offset++;
		ret[i] = ft_get_a_split((s + offset), c);
		i++;
		offset += ft_wlen((s + offset), c);
	}
	ret[wcount] = NULL;
	return (ret);
}
