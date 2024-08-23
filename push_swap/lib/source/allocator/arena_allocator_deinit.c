/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_allocator_deinit.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:38:04 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/08 11:38:05 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

static void	*arena_deinit_child(struct s_allocator *parent,
		struct s_allocator *child)
{
	if (child != 0)
	{
		parent->dealloc(parent, child->region);
		parent->dealloc(parent, child);
	}
	return (0);
}

struct s_allocator	*arena_allocator_deinit(struct s_allocator *self)
{
	struct s_allocator	*parent;
	struct s_allocator	*child;
	struct s_list		*list;
	struct s_list		*temp;

	if (!self)
		return (0);
	parent = self->parent;
	list = self->next;
	while (list)
	{
		list = list->next;
		temp = list_pop_at(&list, 0);
		if (temp != 0)
		{
			child = (struct s_allocator *)temp->data;
			parent->dealloc(parent, temp);
			arena_deinit_child(parent, child);
		}
	}
	parent->dealloc(parent, self->region);
	return (parent->dealloc(parent, self));
}
