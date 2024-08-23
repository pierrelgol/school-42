/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linker_expand_all_variables.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:59:45 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/06 15:59:46 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*token_expand(t_token *const key, t_envmap *map)
{
	t_token	*result;
	char	*value;

	result = token_create();
	value = (char *)envmap_get(map, (key->string + 1));
	if (value != NULL)
	{
		token_set_str(result, value);
		if (value[0] == '/')
			token_set_kind(result, KIND_PATH);
	}
	else
	{
		token_set_str(result, "");
		token_set_kind(result, KIND_ERROR);
	}
	return (result);
}

void	linker_expand_all_variables(t_linker *const self,
		t_list *const token_pool, t_list *const token_pool_linked)
{
	t_list_iter	*it;
	t_token		*curr;

	it = list_iter_create(token_pool);
	while (!it_end(it))
	{
		curr = it_peek_curr(it);
		if (curr && curr->kind == KIND_VAR)
			list_push_back(token_pool_linked, (uintptr_t)token_expand(curr,
					self->envmap));
		else
			list_push_back(token_pool_linked, (uintptr_t)token_clone(curr));
		it_advance(it);
	}
	it = list_iter_destroy(it);
}
