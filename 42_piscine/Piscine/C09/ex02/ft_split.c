/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 12:42:49 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/22 12:42:52 by pollivie         ###   ########.fr       */
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
		if (set[(int)*(str - 1)] != 1)
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

	if (!str || !charset)
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

// #include <stdio.h>
// int main(int argc, char **argv)
// {
// 	char **result;
// 	char *set;
// 	int index;
// 	int length;

// 	if (argc >= 2)
// 	{
// 		index = 0;
// 		set = (char [255]){0};
// 		while(argv[2][index])
// 			set[(int)argv[2][index++]]++;
// 		length = ft_get_wcount(argv[1], set);
// 		printf("words = %d\n",length);
// 		result = ft_split(argv[1], argv[2]);
// 		for (int i = 0; i <= length; i++)
// 		{
// 			printf("result[%d] = %s\n",i,result[i]);
// 			free(result[i]);
// 		}
// 		free(result);
// 	}
// 	return (0);
// }
