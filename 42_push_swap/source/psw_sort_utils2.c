/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_sort_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 11:25:00 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/25 11:25:00 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <limits.h>

int	psw_index_of(int *array, int len, int value)
{
	int	index;

	if (!array || len == 0)
		return (-1);
	index = 0;
	while (index < len)
	{
		if (array[index] == value)
			return (index);
		++index;
	}
	return (-1);
}

int	psw_index_of_next_min(int *array, int len, int min)
{
	int	index;

	if (!array || len == 0)
		return (0);
	index = 0;
	while (index < len)
	{
		if (array[index] <= min)
			break ;
		++index;
	}
	return (index);
}

void	psw_move_min_top(t_psw *container, t_id select)
{
	t_istack	*stack;
	int			index;
	int			min;

	if (select == ID_STACK_A)
		stack = container->a;
	else
		stack = container->b;
	index = 0;
	min = psw_get_min(stack->ptr, stack->len);
	index = psw_index_of(stack->ptr, stack->len, min);
	if (index <= stack->len / 2)
		psw_rotate_until_top(container, select, min);
	else
		psw_reverse_rotate_until_top(container, select, min);
}

void	psw_move_max_top(t_psw *container, t_id select)
{
	t_istack	*stack;
	int			index;
	int			max;

	if (select == ID_STACK_A)
		stack = container->a;
	else
		stack = container->b;
	index = 0;
	max = psw_get_max(stack->ptr, stack->len);
	index = psw_index_of(stack->ptr, stack->len, max);
	if (index <= stack->len / 2)
		psw_rotate_until_top(container, select, max);
	else
		psw_reverse_rotate_until_top(container, select, max);
}
