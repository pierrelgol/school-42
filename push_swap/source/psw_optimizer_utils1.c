/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_optimizer_utils1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 11:25:22 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/25 11:25:23 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	psw_find_partition_size(int input_size)
{
	int	partion_size;

	if (input_size <= 120)
		return (18);
	else if (input_size <= 500)
		return (50);
	partion_size = square_root(input_size) * 2;
	while (partion_size % 2 != 0)
		++partion_size;
	return (partion_size);
}

int	psw_find_simulation_depth(int input_size)
{
	int	depth;

	depth = square_root(input_size);
	while (depth % 2 != 0)
		++depth;
	return (depth);
}

int	psw_get_instruction_count(t_optimiser *optimizer)
{
	int	decount;
	int	count;

	count = psw_get_count(optimizer->cmd);
	decount = psw_get_decount(optimizer->cmd);
	return (count + decount);
}

bool	psw_count_under_threshold(t_optimiser *optimizer)
{
	if (optimizer->size <= 120 && optimizer->best_score <= 700)
		return (true);
	if (optimizer->size == 500 && optimizer->best_score <= 5500)
		return (true);
	else
		return (optimizer->best_score <= optimizer->size * 11);
}

void	psw_maybe_update_score(t_optimiser *optimizer, t_cmd cmd)
{
	if (cmd == RA)
	{
		if (optimizer->ra_score < optimizer->best_score)
		{
			optimizer->best_score = optimizer->ra_score;
			optimizer->best_shift = optimizer->ra_shift;
			optimizer->best_cmd = RA;
		}
	}
	else if (cmd == RRA)
	{
		if (optimizer->rra_score < optimizer->best_score)
		{
			optimizer->best_score = optimizer->rra_score;
			optimizer->best_shift = optimizer->rra_shift;
			optimizer->best_cmd = RRA;
		}
	}
	else
	{
		optimizer->best_cmd = NO_OP;
		optimizer->best_score = optimizer->base_score;
	}
}
