/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_identify_all_pipes.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:01:37 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/06 15:01:38 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lexer_identify_all_pipes(t_list_iter *const it)
{
	t_token	*token;

	if (!it)
		return ;
	it_save(it);
	while (!it_end(it))
	{
		token = it_peek_curr(it);
		if (token && token_get_kind(token) == KIND_NO_KIND)
		{
			if (token->len == 1 && token->string[0] == '|')
				token_set_kind(token, KIND_PIPE);
		}
		it_advance(it);
	}
	it_restore(it);
}
