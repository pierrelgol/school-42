/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_identify_all_builtins.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:01:11 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/06 15:01:12 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lexer_identify_all_builtins(t_list_iter *const it)
{
	t_token	*token;

	const char *const builtins = "echocdenvexportunsetpwd";
	if (!it)
		return ;
	it_save(it);
	while (!it_end(it))
	{
		token = it_peek_curr(it);
		if (token && token_get_kind(token) == KIND_NO_KIND)
		{
			if (token->len >= 1 && string_search(builtins, token_get_str(token),
					string_length(builtins)) != NULL)
				token_set_kind(token, KIND_BLTN);
		}
		it_advance(it);
	}
	it_restore(it);
}
