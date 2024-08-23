/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_sort1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 11:34:07 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/25 11:34:08 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	psw_sort2(t_psw *container, t_istack *a)
{
	if (a->ptr[0] > a->ptr[1])
		psw_rotate(container, ID_STACK_A);
}

void	psw_sort3(t_psw *container, t_istack *a)
{
	t_vec4	v;

	v = (t_vec4){.a = a->ptr[0], .b = a->ptr[1], .c = a->ptr[2]};
	if (v.a > v.b)
	{
		if (v.b < v.c && v.c < v.a)
			psw_rotate(container, ID_STACK_A);
		else
			psw_swap(container, ID_STACK_A);
	}
	v = (t_vec4){.a = a->ptr[0], .b = a->ptr[1], .c = a->ptr[2]};
	if (v.c < v.a && v.a < v.b)
		psw_reverse_rotate(container, ID_STACK_A);
	v = (t_vec4){.a = a->ptr[0], .b = a->ptr[1], .c = a->ptr[2]};
	if (v.a < v.c && v.c < v.b)
	{
		psw_swap(container, ID_STACK_A);
		psw_sort3(container, a);
	}
}

void	psw_sort4(t_psw *container, t_istack *a)
{
	if (!psw_sorted(a->ptr, a->len))
	{
		psw_move_min_top(container, ID_STACK_A);
		psw_push_b(container);
		if (!psw_sorted(a->ptr, a->len))
			psw_sort3(container, a);
		psw_push_a(container);
	}
}

void	psw_sort5(t_psw *container, t_istack *a)
{
	if (!psw_sorted(a->ptr, a->len))
	{
		psw_move_min_top(container, ID_STACK_A);
		psw_push_b(container);
		psw_move_min_top(container, ID_STACK_A);
		psw_push_b(container);
		if (!psw_sorted(a->ptr, a->len))
			psw_sort3(container, a);
		psw_push_a(container);
		psw_push_a(container);
	}
}
