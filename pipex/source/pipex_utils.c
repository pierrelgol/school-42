/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:29:21 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/22 13:29:22 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	**pipex_split_destroy(char **split)
{
	uint64_t	i;

	i = 0;
	while (split[i])
	{
		memory_dealloc(split[i]);
		++i;
	}
	memory_dealloc(split);
	return (0);
}

char	**pipex_split(char *string, char *delim)
{
	char		**result;
	uint64_t	size;
	uint64_t	i;

	i = 0;
	size = string_count_token(string, delim);
	result = memory_zalloc(size * sizeof(char *) + 8);
	while (i < size)
	{
		string += string_span(string, delim);
		if (*string != '\0')
		{
			result[i] = memory_dupz(string, string_cspan(string, delim));
			if (!result[i])
				return (pipex_split_destroy(result));
		}
		string += string_cspan(string, delim);
		++i;
	}
	result[i] = 0;
	return (result);
}

char	*pipex_joins(char *str1, char *str2, char *str3)
{
	char		*result;
	uint64_t	size;

	size = string_length(str1) + string_length(str2) + string_length(str3) + 1;
	result = memory_zalloc(size);
	string_lconcat(result, str1, size);
	string_lconcat(result, str2, size);
	string_lconcat(result, str3, size);
	return (result);
}

int	pipex_file_open(char *name, char *mode)
{
	int	fd;
	int	permissions;

	permissions = file_mode(mode);
	fd = open(name, permissions, 0777);
	return (fd);
}
