/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_command_utils1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 12:10:25 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/25 12:10:25 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	psw_rotate_until_top(t_psw *container, t_id select, int num)
{
	t_istack	*stack;
	int			*array;

	if (select == ID_STACK_A)
		stack = container->a;
	else
		stack = container->b;
	array = stack->ptr;
	while (array[0] != num)
		psw_rotate(container, select);
}

void	psw_reverse_rotate_until_top(t_psw *container, t_id select, int num)
{
	t_istack	*stack;
	int			*array;

	if (select == ID_STACK_A)
		stack = container->a;
	else
		stack = container->b;
	array = stack->ptr;
	while (array[0] != num)
		psw_reverse_rotate(container, select);
}

void	psw_nrotate(t_psw *container, t_id select, int n)
{
	int	count;

	count = 0;
	while (count < n)
	{
		psw_rotate(container, select);
		++count;
	}
}

void	psw_nreverse_rotate(t_psw *container, t_id select, int n)
{
	int	count;

	count = 0;
	while (count < n)
	{
		psw_reverse_rotate(container, select);
		++count;
	}
}
