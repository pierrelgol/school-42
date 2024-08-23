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

static int	split_is_charset(char source, char ch)
{
	return (source == ch);
}

static int	split_get_word_count(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && split_is_charset(*s, c))
			s++;
		if (*s && !split_is_charset(*s, c))
		{
			count++;
			while (*s && !split_is_charset(*s, c))
				s++;
		}
	}
	return (count);
}

static char	*split_make_word(char const *s, char c)
{
	char	*word;
	int		wlen;

	wlen = 0;
	while (s[wlen] && !split_is_charset(s[wlen], c))
		++wlen;
	word = malloc(sizeof(char) * (wlen + 1));
	if (!word)
		return (NULL);
	wlen = 0;
	while (s[wlen] && !split_is_charset(s[wlen], c))
	{
		word[wlen] = s[wlen];
		++wlen;
	}
	word[wlen] = '\0';
	return (word);
}

char	**ft_split(char const *src, char ch)
{
	char	**result;
	int		word_count;
	int		index;

	word_count = split_get_word_count(src, ch);
	result = malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (NULL);
	index = 0;
	while (*src)
	{
		while (*src && split_is_charset(*src, ch))
			src++;
		if (*src && !split_is_charset(*src, ch))
		{
			result[index] = split_make_word(src, ch);
			index++;
			while (*src && !split_is_charset(*src, ch))
				src++;
		}
	}
	result[index] = NULL;
	return (result);
}
