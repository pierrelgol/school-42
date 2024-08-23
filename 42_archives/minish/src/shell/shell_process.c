/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:24:10 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/04 16:26:08 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void shell_resolve_all(t_list *token_list, t_resolver *resolver)
{
	t_list_iter *it;
	t_token     *token;

	it = list_iter_create(token_list);
	while (!it_end(it))
	{
		token = it_peek_curr(it);
		if (token && (token->kind == KIND_ID || token->kind == KIND_ARG))
		{
			if (resolve_exe(resolver, token))
				token_set_kind(token, KIND_CMD);
		}
		it_advance(it);
	}
	it = list_iter_destroy(it);
}

bool shell_process(t_shell *self)
{
	tokenizer_tokenize(self->tokenizer, self->line);
	dbg_tokenizer(self->tokenizer);
	lexer_lex(self->lexer);
	dbg_lexer(self->lexer);
	linker_link(self->linker);
	dbg_linker(self->linker);
	lexer_relex(self->lexer);
	dbg_lexer(self->lexer);
	shell_resolve_all(self->token_pool, self->resolver);
	parser_parse(self->parser);
	dbg_parser(self->parser);
	shell_expression_to_cmd_table(self->table_list, self->parser->expr_list);
	// exec_parent_process(self->table_list, self->envp);
	return (true);
}
