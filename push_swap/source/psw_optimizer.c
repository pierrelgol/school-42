/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_optimizer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 11:25:14 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/25 11:25:15 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	psw_reset_state(t_optimiser *optimizer, int byte_size)
{
	t_istack	*a;
	t_istack	*b;
	t_buffer	*cmd;

	a = optimizer->a;
	b = optimizer->b;
	cmd = optimizer->cmd;
	a->len = optimizer->size;
	b->len = 0;
	memory_copy(a->ptr, optimizer->copy, byte_size);
	memory_set(b->ptr, 0x00, byte_size);
	buffer_clear(cmd);
}

static void	psw_simulate_base_case(t_psw *container, t_optimiser *optimizer)
{
	psw_partition_sort(container, optimizer->a, optimizer->b,
		optimizer->part_size);
	optimizer->base_score = psw_get_instruction_count(optimizer);
	psw_reset_state(optimizer, optimizer->size * sizeof(int));
}

static void	psw_simulate_ra_case(t_psw *container, t_optimiser *optimizer)
{
	optimizer->ra_shift++;
	psw_nrotate(container, ID_STACK_A, optimizer->ra_shift);
	psw_partition_sort(container, optimizer->a, optimizer->b,
		optimizer->part_size);
	optimizer->ra_score = psw_get_instruction_count(optimizer);
	psw_reset_state(optimizer, optimizer->size * sizeof(int));
}

static void	psw_simulate_rra_case(t_psw *container, t_optimiser *optimizer)
{
	optimizer->rra_shift++;
	psw_nreverse_rotate(container, ID_STACK_A, optimizer->rra_shift);
	psw_partition_sort(container, optimizer->a, optimizer->b,
		optimizer->part_size);
	optimizer->rra_score = psw_get_instruction_count(optimizer);
	psw_reset_state(optimizer, optimizer->size * sizeof(int));
}

void	psw_optimize(t_psw *container, t_optimiser *optimizer)
{
	int	current_depth;
	int	maximum_depth;

	maximum_depth = psw_find_simulation_depth(container->size);
	psw_simulate_base_case(container, optimizer);
	psw_maybe_update_score(optimizer, NO_OP);
	current_depth = 0;
	while (current_depth++ < maximum_depth)
	{
		psw_simulate_ra_case(container, optimizer);
		psw_maybe_update_score(optimizer, RA);
		if (psw_count_under_threshold(optimizer))
			return ;
	}
	current_depth = 0;
	while (current_depth++ < maximum_depth)
	{
		psw_simulate_rra_case(container, optimizer);
		psw_maybe_update_score(optimizer, RRA);
		if (psw_count_under_threshold(optimizer))
			return ;
	}
}
