/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:50:51 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/05 09:50:51 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_expression_kind	parser_guess_expression_kind(t_token_kind tok_kind)
{
	if (tok_kind == KIND_ID || tok_kind == KIND_CMD || tok_kind == KIND_PATH)
		return (EXPR_COMMAND);
	else if (tok_kind == KIND_BLTN)
		return (EXPR_BUILTIN);
	else if (tok_kind == KIND_EQL || tok_kind == KIND_VAR)
		return (EXPR_ASSIGNMENT);
	else if (tok_kind == KIND_PIPE)
		return (EXPR_PIPE);
	else if (tok_kind == KIND_LRDIR)
		return (EXPR_LEFT_REDIR);
	else if (tok_kind == KIND_RRDIR)
		return (EXPR_RIGHT_REDIR);
	else if (tok_kind == KIND_APPEND)
		return (EXPR_APPEND);
	else if (tok_kind == KIND_HERE_DOC)
		return (EXPR_HERE_DOC);
	else
		return (EXPR_COMMAND);
}

bool	parser_parse(t_parser *const self)
{
	t_expression_kind	kind;
	t_expression		*expr;
	t_token				*token;

	if (!self)
		return (false);
	while (!list_is_empty(self->token_pool))
	{
		token = (t_token *)list_peek_front(self->token_pool);
		if (token)
		{
			kind = parser_guess_expression_kind(token->kind);
			expr = expression_create();
			expr->kind = kind;
			expression_collect(expr, self->token_pool, kind);
			list_push_back(self->expr_list, (uintptr_t)expr);
		}
	}
	self->is_dirty = true;
	return (true);
}
