/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:48:56 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/04 13:48:57 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	*shell_create(const int32_t argc, char **argv, char **envp)
{
	t_shell	*self;

	self = memory_alloc(sizeof(t_shell));
	if (!self)
		return (NULL);
	self->argc = argc;
	self->argv = argv;
	self->envp = envp;
	self->line = NULL;
	self->envmap = envmap_create(envp);
	self->token_pool = list_create();
	self->tokenizer = tokenizer_create(self->token_pool);
	self->lexer = lexer_create(self->token_pool, self->envmap);
	self->parser = parser_create(self->token_pool);
	self->linker = linker_create(self->token_pool, self->envmap);
	self->resolver = resolver_create(self->token_pool, self->envmap);
	self->interpreter = interpreter_create(self->parser->expr_list);
	self->table_list = list_create();
	self->is_dirty = false;
	return (self);
}
