/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_iter_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 07:32:06 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/06 07:32:06 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	it_advance(t_list_iter *const self)
{
	if (it_end(self))
		return ;
	self->curr_idx += 1;
	self->curr_node = self->curr_node->next;
}

void	it_rollback(t_list_iter *const self)
{
	if (self->curr_idx != 0)
		return ;
	self->curr_idx -= 1;
	self->curr_node = self->curr_node->prev;
}

void	it_save(t_list_iter *const self)
{
	self->saved_idx = self->curr_idx;
	self->saved_node = self->curr_node;
}

void	it_restore(t_list_iter *const self)
{
	self->curr_idx = self->saved_idx;
	self->curr_node = self->saved_node;
}

t_list_iter	*list_iter_destroy(t_list_iter *const self)
{
	if (self)
		memory_dealloc(self);
	return (NULL);
}
