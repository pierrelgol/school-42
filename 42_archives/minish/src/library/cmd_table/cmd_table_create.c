/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_table_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:29:29 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/08 14:29:29 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

static int64_t string_last_index_of(const char *const str, const char ch)
{
	int64_t last_index;
	int64_t index;

	last_index = -1;
	index = 0;
	if (!str)
		return (-1);
	while (str[index])
	{
		if (str[index] == ch)
			last_index = index;
		++index;
	}
	return (last_index);
}

char	**list_to_split_token(t_list *const self)
{
	char		**result;
	uint64_t	size;
	uint64_t	i;

	size = list_size(self);
	i = 0;
	result = string_split_create(size + 1);
	if (!result)
		return (NULL);
	while (i < size)
	{
		result[i] = string_clone(token_get_str((t_token*)list_peek_at(self, i)));
		++i;
	}
	result[i] = NULL;
	return (result);
}


t_cmd_table *cmd_table_create(t_expression *const expr, const uint64_t id)
{
	t_cmd_table *self;
	int64_t      index;

	self = (t_cmd_table *) memory_alloc(sizeof(t_cmd_table));
	if (!self)
		return (NULL);
	self->cmd_argv = list_to_split_token(expr->tokens);
	self->cmd_absolute_path = self->cmd_argv[1];
	self->cmd_argc = list_size(expr->tokens);
	index = string_last_index_of(self->cmd_absolute_path, '/');
	if (index != -1)
		self->cmd_basename = string_clone(&self->cmd_absolute_path[index]);
	else
		self->cmd_basename = string_clone("");
	memory_fill(self->fd_array, INIT_VALUE, sizeof(int32_t) * 3);
	self->id = id;
	self->kind = expr->kind;
	return (self);
}
