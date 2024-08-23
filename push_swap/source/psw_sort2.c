/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_sort2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 11:34:13 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/25 11:34:14 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	psw_move_num_top(t_psw *container, int num, enum e_id select)
{
	t_istack	*stack;
	int			index;

	if (select == ID_STACK_A)
		stack = container->a;
	else
		stack = container->b;
	index = psw_index_of(stack->ptr, stack->len, num);
	if (index == -1)
		return ;
	if (index <= stack->len / 2)
		psw_rotate_until_top(container, select, num);
	else
		psw_reverse_rotate_until_top(container, select, num);
}

static void	psw_move_num_top2(t_psw *container, int num1, int num2)
{
	psw_move_num_top(container, num1, ID_STACK_B);
	psw_push_a(container);
	psw_move_num_top(container, num2, ID_STACK_B);
	psw_push_a(container);
}

static void	psw_empty_b(t_psw *container, t_istack *a, t_istack *b)
{
	int	n1;
	int	n2;
	int	i1;
	int	i2;

	while (b->len)
	{
		n1 = psw_get_max(b->ptr, b->len);
		i1 = psw_index_of(b->ptr, b->len, n1);
		n2 = psw_get_next_max(b->ptr, b->len, n1);
		i2 = psw_index_of(b->ptr, b->len, n2);
		if (i1 > b->len / 2)
			i1 = b->len - i1;
		if (i2 > b->len / 2)
			i2 = b->len - i2;
		if (i1 < i2)
			psw_move_num_top2(container, n1, n2);
		else
			psw_move_num_top2(container, n2, n1);
		if (a->ptr[0] > a->ptr[1])
			psw_swap(container, ID_STACK_A);
	}
}

void	psw_partition_sort(t_psw *container, t_istack *a, t_istack *b,
		int psize)
{
	int	index;
	int	min;
	int	i;

	while (a->len)
	{
		i = 0;
		min = psw_get_min(a->ptr, a->len);
		while (i++ < psize)
		{
			min = psw_get_next_min(a->ptr, a->len, min);
			if (i == psize / 2)
				a->mid = min;
		}
		i = 0;
		while (i++ < psize)
		{
			index = psw_index_of_next_min(a->ptr, a->len, min);
			psw_move_num_top(container, a->ptr[index], ID_STACK_A);
			psw_push_b(container);
			if (b->ptr[0] < a->mid)
				psw_rotate(container, ID_STACK_B);
		}
	}
	psw_empty_b(container, a, b);
}
