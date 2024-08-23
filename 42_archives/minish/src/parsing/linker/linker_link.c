/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linker_link.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:47:30 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/05 09:47:31 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	linker_update_list(t_list *const original_list,
		t_list *const new_list)
{
	list_clear(original_list, token_dtor);
	list_dump(original_list, new_list);
}

bool	linker_link(t_linker *const self)
{
	if (!self)
		return (false);
	if (self->is_dirty)
		linker_clear(self);
	linker_link_all_left_redirs(self->token_pool, self->token_pool_linked);
	linker_update_list(self->token_pool, self->token_pool_linked);
	linker_link_all_right_redirs(self->token_pool, self->token_pool_linked);
	linker_update_list(self->token_pool, self->token_pool_linked);
	linker_link_all_single_quotes(self->token_pool, self->token_pool_linked);
	linker_update_list(self->token_pool, self->token_pool_linked);
	linker_expand_all_variables(self, self->token_pool,
		self->token_pool_linked);
	linker_update_list(self->token_pool, self->token_pool_linked);
	linker_link_all_slash_id(self->token_pool, self->token_pool_linked);
	linker_update_list(self->token_pool, self->token_pool_linked);
	linker_link_all_path(self->token_pool, self->token_pool_linked);
	linker_update_list(self->token_pool, self->token_pool_linked);
	linker_link_all_double_quotes(self->token_pool, self->token_pool_linked);
	linker_update_list(self->token_pool, self->token_pool_linked);
	linker_link_all_remaining_slash(self->token_pool, self->token_pool_linked);
	linker_update_list(self->token_pool, self->token_pool_linked);
	linker_remove_all_spaces(self->token_pool, self->token_pool_linked);
	linker_update_list(self->token_pool, self->token_pool_linked);
	self->is_dirty = true;
	return (true);
}
