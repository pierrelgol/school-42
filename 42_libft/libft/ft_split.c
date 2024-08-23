/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:57:52 by pollivie          #+#    #+#             */
/*   Updated: 2023/10/02 11:57:54 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

static int	ft_token_count(const char *s, char tok)
{
	int	tcount;

	tcount = 0;
	while (*s)
	{
		while (*s && *s == tok)
			++s;
		if (*s != '\0')
			++tcount;
		while (*s && *s != tok)
			++s;
	}
	return (tcount);
}

static int	ft_token_len(const char *s, char tok)
{
	int	tlen;

	tlen = 0;
	while (*s && *s != tok)
	{
		++s;
		++tlen;
	}
	return (tlen);
}

static char	*ft_token_split(const char *s, char tok)
{
	char	*result;
	size_t	rlen;
	size_t	i;

	rlen = ft_token_len(s, tok);
	if (rlen == 0)
		return (NULL);
	result = (char *) malloc(sizeof(char) * rlen + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < rlen)
		result[i++] = *s++;
	result[rlen] = '\0';
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char		**result;
	size_t		size;
	size_t		index;

	if (!s)
		return (NULL);
	size = ft_token_count(s, c);
	result = (char **) malloc(sizeof(char *) * size + 1);
	if (!result)
		return (NULL);
	index = 0;
	while (index < size)
	{
		while (*s && *s == c)
			++s;
		if (*s != '\0')
			result[index] = ft_token_split(s, c);
		while (*s && *s != c)
			++s;
		++index;
	}
	result[size] = NULL;
	return (result);
}
