/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bissenma <bissenma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:02:53 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/24 15:51:48 by bissenma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/num_stack.h"

t_stack	*stack_init(int nbr_elem)
{
	t_stack	*self;

	self = (t_stack *)malloc(sizeof(t_stack) * 1);
	if (!self)
		return (NULL);
	*self = (t_stack){0, 0, DEFAULTV, NULL};
	if (nbr_elem == 0)
		self->elems = (char *)malloc(STACK_DEFAULT_SIZE);
	else
		self->elems = (char *)malloc(nbr_elem);
	self->capacity = (nbr_elem);
	if (!self->elems)
	{
		free(self);
		return (NULL);
	}
	return (self);
}

bool	stack_push(t_stack *self, char *elem)
{
	if (!self)
		return (false);
	if ((self->count + 1) < self->capacity)
		self->elems[self->count++] = *elem;
	return (true);
}

char	*stack_pop(t_stack *self)
{
	if (!self)
		return (NULL);
	if ((self->count - 1) >= 0)
		return (&(self->elems[self->count--]));
	return (NULL);
}

char	*stack_peek(t_stack *self, int index)
{
	if (!self)
		return (NULL);
	if (self->count >= index && index <= self->capacity)
		return (&(self->elems[index]));
	return (NULL);
}

void	stack_dispose(t_stack *self)
{
	if (self)
	{
		if (self->elems)
		{
			free(self->elems);
		}
		free(self);
	}
}
