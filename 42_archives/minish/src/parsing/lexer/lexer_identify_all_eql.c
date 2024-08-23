/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_identify_all_eql.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:00:48 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/06 15:00:48 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lexer_identify_all_eql(t_list_iter *const it)
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
			if (string_compare(token->string, "=") == 0)
				token_set_kind(token, KIND_EQL);
		}
		it_advance(it);
	}
	it_restore(it);
}
