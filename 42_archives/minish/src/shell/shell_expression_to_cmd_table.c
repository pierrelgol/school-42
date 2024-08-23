/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_expression_to_cmd_table.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:26:53 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/08 14:26:55 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static void shell_expression_configure_table(t_cmd_table *table, t_expression *next)
// {
// 	if (next->)
	
// }

bool shell_expression_to_cmd_table(t_list *table_list, t_list *expr_list)
{
	t_list_iter  *it;
	t_cmd_table  *table;
	t_expression *curr;
	t_expression *next;
	uint64_t      index;

	it = list_iter_create(expr_list);
	index = 1;
	while (!it_end(it))
	{
		curr = it_peek_curr(it);
		next = it_peek_next(it);
		(void)next;
		if (curr && (curr->kind == KIND_CMD || curr->kind == KIND_BLTN))
		{
			table = cmd_table_create(curr, index);
			list_push_back(table_list, (uintptr_t) table);
		}
		it_advance(it);
		++index;
	}
	it = list_iter_destroy(it);
	return (true);
}
