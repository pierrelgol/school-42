/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 11:26:10 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/25 11:26:10 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <string.h>

void	psw_push_a(t_psw *self)
{
	t_istack	*a;
	t_istack	*b;
	int			value;

	a = self->a;
	b = self->b;
	if (b->len == 0)
		return ;
	a->len += 1;
	b->len -= 1;
	value = b->ptr[0];
	memory_move(b->ptr, b->ptr + 1, b->len * sizeof(int));
	memory_move(a->ptr + 1, a->ptr, a->len * sizeof(int));
	a->ptr[0] = value;
	buffer_putch(self->cmd, PA);
}

void	psw_push_b(t_psw *self)
{
	t_istack	*a;
	t_istack	*b;
	int			value;

	a = self->a;
	b = self->b;
	if (a->len == 0)
		return ;
	b->len++;
	a->len--;
	value = a->ptr[0];
	memory_move(a->ptr, a->ptr + 1, a->len * sizeof(int));
	memory_move(b->ptr + 1, b->ptr, b->len * sizeof(int));
	b->ptr[0] = value;
	buffer_putch(self->cmd, PB);
}

void	psw_swap(t_psw *self, t_id select)
{
	t_istack	*s;
	int			value;

	if (select == ID_STACK_A)
		s = self->a;
	else
		s = self->b;
	if (s->len == 0)
		return ;
	value = s->ptr[0];
	s->ptr[0] = s->ptr[1];
	s->ptr[1] = value;
	if (select == ID_STACK_A)
		buffer_putch(self->cmd, SA);
	else
		buffer_putch(self->cmd, SB);
}

void	psw_rotate(t_psw *self, t_id select)
{
	t_istack	*s;
	int			value;

	if (select == ID_STACK_A)
		s = self->a;
	else
		s = self->b;
	if (s->len == 0)
		return ;
	value = s->ptr[0];
	memory_move(s->ptr, s->ptr + 1, s->len * sizeof(int));
	s->ptr[s->len - 1] = value;
	if (select == ID_STACK_A)
		buffer_putch(self->cmd, RA);
	else
		buffer_putch(self->cmd, RB);
}

void	psw_reverse_rotate(t_psw *self, t_id select)
{
	t_istack	*s;
	int			value;

	if (select == ID_STACK_A)
		s = self->a;
	else
		s = self->b;
	if (s->len == 0)
		return ;
	value = s->ptr[s->len - 1];
	memory_move(s->ptr + 1, s->ptr, s->len * sizeof(int));
	s->ptr[0] = value;
	if (select == ID_STACK_A)
		buffer_putch(self->cmd, RRA);
	else
		buffer_putch(self->cmd, RRB);
}
