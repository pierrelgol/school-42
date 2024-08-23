/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 09:22:23 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/06 09:22:23 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_tok(uintptr_t arg)
{
	t_token	*token;

	token = (t_token *)arg;
	if (token)
		token_print(token);
}

void	dbg_tokenizer(t_tokenizer *const self)
{
	printf("--------------------------------\n");
	printf("TOKENIZER:\n");
	printf("\ninputs:\n");
	for (int i = 0; self->tokens[i]; ++i)
		printf("[%d][%s]\n", i, self->tokens[i]);
	printf("\noutputs:\n");
	list_map(self->token_pool, print_tok);
	printf("--------------------------------\n");
}

void	dbg_lexer(t_lexer *const self)
{
	printf("--------------------------------\n");
	printf("LEXER:\n");
	list_map(self->token_pool, print_tok);
	printf("--------------------------------\n");
}

void	dbg_linker(t_linker *const self)
{
	printf("--------------------------------\n");
	printf("LINKER :\n");
	list_map(self->token_pool, print_tok);
	printf("--------------------------------\n");
}

void	dbg_parser(t_parser *const self)
{
	t_expression	*expr;
	t_node			*node;
	uint64_t		i;

	printf("--------------------------------\n");
	printf("PARSER:\n");
	i = 0;
	node = self->expr_list->head;
	while (node)
	{
		expr = (t_expression *)node->data;
		if (expr)
			expression_print(expr, i);
		node = node->next;
		++i;
	}
	printf("--------------------------------\n");
}
