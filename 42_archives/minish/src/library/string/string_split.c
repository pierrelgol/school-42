/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:45:13 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/04 11:45:13 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

char	*string_get_next_word(char **source, const char *const delimiters)
{
	char		*result;
	char		*ptr;
	uint64_t	start;
	uint64_t	end;

	if (!source || !*source || !delimiters)
		return (NULL);
	ptr = *source;
	start = string_span(ptr, delimiters);
	end = string_cspan(&ptr[start], delimiters);
	result = string_nclone(&ptr[start], end);
	if (ptr[start + end] != '\0')
		(*source) = ((*source) + (start + end + 1));
	else
		(*source) = NULL;
	return (result);
}

char	**string_split(const char *const source, const char *const delimiters)
{
	char		**result;
	uint64_t	size;
	uint64_t	i;
	char		*ptr;

	size = string_wcount(source, delimiters);
	result = string_split_create(size + 1);
	if (!result)
		return (NULL);
	i = 0;
	ptr = (char *)source;
	while (i < size)
	{
		result[i] = string_get_next_word(&ptr, delimiters);
		++i;
	}
	result[i] = NULL;
	return (result);
}
