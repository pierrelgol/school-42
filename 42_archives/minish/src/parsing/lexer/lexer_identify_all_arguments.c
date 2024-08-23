/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_identify_all_arguments.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:06:36 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/06 15:06:36 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lexer_identify_all_arguments(t_list_iter *const it)
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
			if (string_is_all(token_get_str(token), is_ascii))
				token_set_kind(token, KIND_ARG);
		}
		it_advance(it);
	}
	it_restore(it);
}
