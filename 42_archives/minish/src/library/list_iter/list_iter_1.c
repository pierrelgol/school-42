/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_iter_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 07:31:56 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/06 07:31:57 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list_iter	*list_iter_create(t_list *list)
{
	t_list_iter	*self;

	self = (t_list_iter *)memory_alloc(sizeof(t_list_iter));
	if (!self)
		return (NULL);
	self->end_idx = list_size(list);
	self->curr_idx = 0;
	self->curr_node = list->head;
	self->saved_idx = 0;
	self->saved_node = self->curr_node;
	return (self);
}

bool	it_end(const t_list_iter *const self)
{
	return (self->curr_idx == self->end_idx);
}

void	*it_peek_curr(const t_list_iter *const self)
{
	if (!it_end(self))
		return ((void *)self->curr_node->data);
	return (NULL);
}

void	*it_peek_prev(const t_list_iter *const self)
{
	if (!it_end(self) && self->curr_idx != 0)
		return ((void *)self->curr_node->prev->data);
	return (NULL);
}

void	*it_peek_next(const t_list_iter *const self)
{
	if (!it_end(self) && (self->curr_idx + 1) != self->end_idx)
		return ((void *)self->curr_node->next->data);
	return (NULL);
}
