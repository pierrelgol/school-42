/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:23:27 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/04 16:23:27 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool shell_clear(t_shell *self)
{
	if (!self || !self->is_dirty)
		return (false);
	tokenizer_clear(self->tokenizer);
	lexer_clear(self->lexer);
	linker_clear(self->linker);
	parser_clear(self->parser);
	interpreter_clear(self->interpreter);
	list_clear(self->token_pool, token_dtor);
	if (self->line)
		memory_dealloc(self->line);
	self->is_dirty = false;
	return (true);
}
