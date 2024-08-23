/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linker_link_all_remaining_slash.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:09:57 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/06 13:09:57 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	linker_join_remaining_slash(t_list_iter *it, t_token *curr,
		t_list *const token_pool_linked)
{
	t_token	*temp1;
	t_token	*temp2;

	temp1 = token_clone(curr);
	while (!it_end(it))
	{
		curr = it_peek_curr(it);
		if (curr->kind == KIND_SLASH)
		{
			temp2 = token_join(temp1, curr, NULL);
			token_destroy(temp1);
			temp1 = temp2;
		}
		else
		{
			temp2 = token_join(temp1, curr, NULL);
			token_destroy(temp1);
			list_push_back(token_pool_linked, (uintptr_t)temp2);
			it_advance(it);
			return ;
		}
		it_advance(it);
	}
	list_push_back(token_pool_linked, (uintptr_t)temp1);
}

void	linker_link_all_remaining_slash(t_list *const token_pool,
		t_list *const token_pool_linked)
{
	t_list_iter	*it;
	t_token		*curr;
	t_token		*next;

	it = list_iter_create(token_pool);
	while (!it_end(it))
	{
		curr = it_peek_curr(it);
		next = it_peek_next(it);
		if (curr && curr->kind == KIND_NO_KIND && next
			&& next->kind == KIND_SLASH)
		{
			it_advance(it);
			linker_join_remaining_slash(it, curr, token_pool_linked);
		}
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
