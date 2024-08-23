/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linker_remove_all_spaces.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:26:27 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/06 13:26:27 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	linker_remove_all_spaces(t_list *const token_pool,
		t_list *const token_pool_linked)
{
	t_list_iter	*it;
	t_token		*token;

	it = list_iter_create(token_pool);
	while (!it_end(it))
	{
		token = it_peek_curr(it);
		if (token && token->kind != KIND_SPC)
			list_push_back(token_pool_linked, (uintptr_t)token_clone(token));
		it_advance(it);
	}
	it = list_iter_destroy(it);
}
