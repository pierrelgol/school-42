/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_identify_all_identifiers.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:00:21 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/06 15:00:21 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lexer_identify_all_identifiers(t_list_iter *const it)
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
			if (string_starts_with(token_get_str(token), is_identifier_start)
				&& string_is_all(token_get_str(token), is_identifier))
				token_set_kind(token, KIND_ID);
		}
		it_advance(it);
	}
	it_restore(it);
}
