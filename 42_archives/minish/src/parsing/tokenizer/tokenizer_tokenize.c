/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_tokenize.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 06:42:27 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/05 06:42:27 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assert.h"
#include "minishell.h"

bool	tokenizer_tokenize(t_tokenizer *const self, char *input)
{
	uint64_t	i;
	t_token		*token;

	if (!self || !input)
		return (false);
	if (self->is_dirty)
		tokenizer_clear(self);
	self->tokens = string_tokenize(input, " \n\t<>\'\"=|/");
	if (!self->tokens)
		return (false);
	i = 0;
	while (self->tokens[i])
	{
		token = token_create();
		token_set_str(token, self->tokens[i]);
		token_set_kind(token, KIND_NO_KIND);
		list_push_back(self->token_pool, (uintptr_t)token);
		++i;
	}
	self->is_dirty = true;
	return (true);
}
