/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 09:39:37 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/13 09:39:38 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_node	*list_remove_at(t_list *list, uint64_t index)
{
	t_node	*parent;
	t_node	*child;

	if (list_is_empty(list))
		return (NULL);
	if (index == 0)
		return (list_remove_front(list));
	if (index >= list_size(list))
		return (list_remove_back(list));
	else
	{
		parent = node_get_nchild(list->head, index - 1);
		child = node_remove_child(parent);
		list->size -= 1;
	}
	return (child);
}

uint64_t	list_size(t_list *self)
{
	return (self->size);
}

t_node	*node_create(uintptr_t data)
{
	t_node	*node;

	node = (t_node *)memory_alloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->next = 0;
	node->data = data;
	return (node);
}

uint64_t	node_count_child(t_node *self)
{
	uint64_t	count;
	t_node		*child;

	if (!self || !self->next)
		return (0);
	count = 0;
	child = self;
	while (child)
	{
		child = child->next;
		++count;
	}
	return (count);
}

t_node	*node_get_nchild(t_node *self, uint64_t n)
{
	t_node	*temp;

	if (!self || n == 0)
		return (self);
	temp = self;
	while (n--)
	{
		if (!temp->next)
			return (temp);
		temp = temp->next;
	}
	return (temp);
}
