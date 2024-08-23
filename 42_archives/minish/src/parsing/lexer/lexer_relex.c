/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_relex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:06:50 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/06 15:06:50 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	lexer_relex(t_lexer *const self)
{
	if (!self)
		return (false);
	if (self->is_dirty)
		lexer_clear(self);
	self->it = list_iter_create(self->token_pool);
	lexer_identify_all_appends(self->it);
	lexer_identify_all_here_docs(self->it);
	lexer_identify_all_builtins(self->it);
	lexer_identify_all_identifiers(self->it);
	lexer_identify_all_arguments(self->it);
	self->is_dirty = true;
	return (true);
}
