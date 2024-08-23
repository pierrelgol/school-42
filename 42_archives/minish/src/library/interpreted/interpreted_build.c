/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreted_build.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:34:50 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/09 13:34:51 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

bool interpreted_is_start_token(t_interpreted_kind inter_kind, t_expression_kind expr_kind)
{
	if (inter_kind == INTER_CMD)
		return (expr_kind == EXPR_COMMAND);
	if (inter_kind == INTER_BUILTIN)
		return (expr_kind == EXPR_BUILTIN);
	return (false);
}

bool interpreted_is_interior_token(t_interpreted_kind inter_kind, t_expression_kind expr_kind)
{
	if (inter_kind == INTER_CMD)
		return (expr_kind == EXPR_RIGHT_REDIR || expr_kind == EXPR_LEFT_REDIR);
	if (inter_kind == INTER_BUILTIN)
		return (expr_kind == EXPR_RIGHT_REDIR || expr_kind == EXPR_LEFT_REDIR);
	return (false);
}

bool interpreted_is_terminal_token(t_interpreted_kind inter_kind, t_expression_kind expr_kind)
{
	if (inter_kind == INTER_CMD)
		return (expr_kind == EXPR_PIPE || expr_kind == EXPR_LEFT_REDIR || expr_kind == EXPR_RIGHT_REDIR);
	if (inter_kind == INTER_BUILTIN)
		return (expr_kind == EXPR_PIPE || expr_kind == EXPR_LEFT_REDIR || expr_kind == EXPR_RIGHT_REDIR);
	return (false);
}

void interpreted_collect(t_interpreted *const self, t_list *const expression_list, t_interpreted_kind kind)
{
	t_expression *expression;

	expression = (t_expression *) list_peek_front(expression_list);
	if (expression && interpreted_is_start_token(kind, expression->kind))
	{
		list_insert_front(self->expr_list, list_remove_front(expression_list));
		while (true)
		{
			expression = (t_expression *) list_peek_front(expression_list);
			if (expression && interpreted_is_interior_token(kind, expression->kind))
				list_insert_back(self->expr_list, list_remove_front(expression_list));
			else
				break;
		}
		expression = (t_expression *) list_peek_front(expression_list);
		if (expression && interpreted_is_terminal_token(kind, expression->kind))
			list_insert_back(self->expr_list, list_remove_front(expression_list));
	}
	else
		list_insert_front(self->expr_list, list_remove_front(expression_list));
}
