/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expression_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 20:14:11 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/06 20:14:11 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

static char	*expr_kind(t_expression_kind kind)
{
	if (kind == EXPR_UNKOWN)
		return ("UNKOWN");
	if (kind == EXPR_APPEND)
		return ("APPEND");
	if (kind == EXPR_ASSIGNMENT)
		return ("ASSIGNMENT");
	if (kind == EXPR_BUILTIN)
		return ("BUILTIN");
	if (kind == EXPR_COMMAND)
		return ("COMMAND");
	if (kind == EXPR_DOUBLE_QUOTES)
		return ("DOUBLE_QUOTES");
	if (kind == EXPR_HERE_DOC)
		return ("HERE_DOC");
	if (kind == EXPR_LEFT_REDIR)
		return ("LEFT_REDIR");
	if (kind == EXPR_PIPE)
		return ("PIPE");
	if (kind == EXPR_QUOTES)
		return ("QUOTES");
	if (kind == EXPR_RIGHT_REDIR)
		return ("RIGHT_REDIR");
	return ("ERROR");
}

void	expression_print(t_expression *const self, uint64_t i)
{
	t_node	*node;
	t_token	*token;

	if (!self || list_is_empty(self->tokens))
		return ;
	node = self->tokens->head;
	printf("EXPRESSION[%lu]:%s\n", i, expr_kind(self->kind));
	while (node)
	{
		token = (t_token *)node->data;
		if (token)
			token_print(token);
		node = node->next;
	}
	printf("\n");
}
