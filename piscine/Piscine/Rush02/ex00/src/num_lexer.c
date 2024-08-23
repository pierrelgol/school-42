/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_lexer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bissenma <bissenma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 10:54:30 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/24 15:56:20 by bissenma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/num_lexer.h"

t_token	*lexer_tokenize(t_file *file)
{
	t_token	*lexed;
	int		size;

	if (!file)
		return (NULL);
	size = lexer_token_count(file->buffer) + 1;
	lexed = (t_token *)malloc(sizeof(t_token) * size);
	if (!lexed)
		return (NULL);
}

int	lexer_isspace(char ch)
{
	return (ch == ' ' || ch == 9 || (ch >= 11 && ch <= 13));
}

int	lexer_isprintable(char ch)
{
	return (ch >= 32 && ch <= 126);
}

int	lexer_is_separator(char ch)
{
	return (ch == ':' || ch == '\n');
}

int	lexer_isalnum(char ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);
	if (ch >= 'A' && ch <= 'Z')
		return (1);
	if (ch >= 'a' && ch <= 'z')
		return (1);
	return (0);
}

int	lexer_token_count(char *buffer)
{
	int index;
	int count;

	index = 0;
	count = 0;
	while (buffer[index] != '\0')
	{
		while (buffer[index] && buffer[index] >= '0' && buffer[index] <= '9')
			++index;
		while (buffer[index] && lexer_isspace(buffer[index]))
			++index;
		if (lexer_is_separator(buffer[index++]))
			++count;
		while (buffer[index] && lexer_isalnum(buffer[index]))
			++index;
		if (lexer_is_separator(buffer[index++]))
			++count;
	}
	return (count);
}