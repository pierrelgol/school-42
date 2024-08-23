/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 03:04:36 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/14 03:04:38 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_get_wcount(char *str, char *set)
{
	int	words;

	words = 0;
	while (*str)
	{
		while (*str && set[(int)*str] == 1)
			++str;
		while (*str && set[(int)*str] == 0)
			++str;
		if (*str)
			++words;
	}
	return (words);
}

int	ft_get_wlen(char *str, char *set)
{
	int	word_length;

	word_length = 0;
	while (str[word_length] && set[(int)str[word_length]] != 1)
		++word_length;
	return (word_length);
}

char	*ft_get_word(char *str, char *set)
{
	char	*word;
	int		word_len;
	int		i;

	i = 0;
	word_len = ft_get_wlen(str, set);
	word = (char *)malloc(sizeof(char) * (word_len + 1));
	if (word == NULL)
		return (NULL);
	while (i < word_len)
		word[i++] = *str++;
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	char	*set;
	int		i;

	if (!str)
		return (NULL);
	set = (char [255]){0};
	while (*charset)
		set[(int)*charset++] = 1;
	i = 0;
	split = (char **)malloc(sizeof(char *) * (ft_get_wcount(str, set) + 1));
	while (*str)
	{
		while (*str && set[(int)*str] == 1)
			++str;
		if (*str && set[(int)*str] == 0)
			split[i++] = ft_get_word(str, set);
		while (*str && set[(int)*str] == 0)
			++str;
	}
	split[i] = NULL;
	return (split);
}

int	main(int argc, char **argv)
{
	char **split;
	int	size;
	

	
}
