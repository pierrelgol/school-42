/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linker_link_all_paths.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:05:16 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/06 16:05:16 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	linker_join_path(t_list_iter *it, t_token *curr,
		t_list *const token_pool_linked)
{
	t_token	*temp1;
	t_token	*temp2;

	temp1 = token_clone(curr);
	it_advance(it);
	while (!it_end(it))
	{
		curr = it_peek_curr(it);
		if (curr && curr->kind == KIND_PATH)
		{
			temp2 = token_join(temp1, curr, NULL);
			token_destroy(temp1);
			temp1 = temp2;
		}
		else
			break ;
		it_advance(it);
	}
	list_push_back(token_pool_linked, (uintptr_t)temp1);
}

void	linker_link_all_path(t_list *const token_pool,
		t_list *const token_pool_linked)
{
	t_list_iter	*it;
	t_token		*curr;

	it = list_iter_create(token_pool);
	while (!it_end(it))
	{
		curr = it_peek_curr(it);
		if (curr && curr->kind == KIND_PATH)
			linker_join_path(it, curr, token_pool_linked);
		else if (curr != NULL)
		{
			list_push_back(token_pool_linked, (uintptr_t)token_clone(curr));
			it_advance(it);
		}
		else
			it_advance(it);
	}
	it = list_iter_destroy(it);
}
