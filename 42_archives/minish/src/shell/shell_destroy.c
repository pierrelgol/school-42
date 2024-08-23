/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:58:30 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/04 13:58:31 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	*shell_destroy(t_shell *self)
{
	if (self)
	{
		if (self->is_dirty)
			shell_clear(self);
		if (self->envmap)
			self->envmap = envmap_destroy(self->envmap);
		if (self->token_pool)
			list_destroy(self->token_pool);
		if (self->tokenizer)
			tokenizer_destroy(self->tokenizer);
		if (self->lexer)
			lexer_destroy(self->lexer);
		if (self->parser)
			parser_destroy(self->parser);
		if (self->resolver)
			resolver_destroy(self->resolver);
		if (self->linker)
			linker_destroy(self->linker);
		if (self->table_list)
			list_destroy(self->table_list);
		if (self->interpreter)
			interpreter_destroy(self->interpreter);
		memory_dealloc(self);
	}
	return (NULL);
}
