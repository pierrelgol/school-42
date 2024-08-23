/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linker_link_all_left_redirs.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:06:49 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/06 13:06:50 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	linker_link_all_left_redirs(t_list *const token_pool,
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
		if (curr && next && curr->kind == KIND_LRDIR
			&& next->kind == KIND_LRDIR)
		{
			list_push_back(token_pool_linked, (uintptr_t)token_join(curr, next,
					NULL));
			it_advance(it);
		}
		else
			list_push_back(token_pool_linked, (uintptr_t)token_clone(curr));
		it_advance(it);
	}
	it = list_iter_destroy(it);
}
