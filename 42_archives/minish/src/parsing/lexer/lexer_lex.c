/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_lex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:45:52 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/05 09:45:53 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	lexer_lex(t_lexer *const self)
{
	if (!self)
		return (false);
	if (self->is_dirty)
		lexer_clear(self);
	self->it = list_iter_create(self->token_pool);
	lexer_identify_all_spaces(self->it);
	lexer_identify_all_quotes(self->it);
	lexer_identify_all_pipes(self->it);
	lexer_identify_all_slashes(self->it);
	lexer_identify_all_dollar(self->it);
	lexer_identify_all_eql(self->it);
	lexer_identify_all_redirs(self->it);
	lexer_identify_all_builtins(self->it);
	lexer_identify_all_identifiers(self->it);
	// list_push_back(self->token_pool, (uintptr_t)token_endtok());
	self->is_dirty = true;
	return (true);
}
