/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 11:08:22 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/25 11:08:23 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	psw_apply_optimization_findings(t_psw *container,
		t_optimiser *optimizer)
{
	t_cmd	best_cmd;
	int		best_shift;

	best_cmd = optimizer->best_cmd;
	best_shift = optimizer->best_shift;
	if (best_cmd == RA)
		psw_nrotate(container, ID_STACK_A, best_shift);
	else if (best_cmd == RRA)
		psw_nreverse_rotate(container, ID_STACK_A, best_shift);
	else
		return ;
}

static void	psw_sort_complex(t_psw *container, t_optimiser *optimizer)
{
	memory_copy(optimizer->copy, optimizer->a->ptr, optimizer->size
		* sizeof(int));
	optimizer->part_size = psw_find_partition_size(container->size);
	psw_optimize(container, optimizer);
	psw_apply_optimization_findings(container, optimizer);
	psw_partition_sort(container, container->a, container->b,
		optimizer->part_size);
}

bool	psw_start(t_psw *container)
{
	if (!psw_parse(container, container->a, container->inputs, container->size))
		return (false);
	if (!psw_sorted(container->a->ptr, container->a->len))
	{
		if (container->a->len == 2)
			psw_sort2(container, container->a);
		else if (container->size == 3)
			psw_sort3(container, container->a);
		else if (container->size == 4)
			psw_sort4(container, container->a);
		else if (container->size == 5)
			psw_sort5(container, container->a);
		else
			psw_sort_complex(container, container->optimiser);
		psw_print(container);
	}
	return (true);
}
