/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expression_collect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 20:04:55 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/06 20:04:55 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

void	expression_collect(t_expression *const self, t_list *const token_list,
		t_expression_kind kind)
{
	t_token	*token;

	token = (t_token *)list_peek_front(token_list);
	if (token && expression_is_start_token(kind, token->kind))
	{
		list_insert_front(self->tokens, list_remove_front(token_list));
		while (true)
		{
			token = (t_token *)list_peek_front(token_list);
			if (token && expression_is_interior_token(kind, token->kind))
				list_insert_back(self->tokens, list_remove_front(token_list));
			else
				break ;
		}
		token = (t_token *)list_peek_front(token_list);
		if (token && expression_is_terminal_token(kind, token->kind))
		{
			list_insert_back(self->tokens, list_remove_front(token_list));
			self->is_complete = true;
		}
		else
			self->is_complete = false;
	}
	else
	{
		list_insert_front(self->tokens, list_remove_front(token_list));
		self->is_complete = false;
		self->kind = EXPR_UNKOWN;
	}
}
