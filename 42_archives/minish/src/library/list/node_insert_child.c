/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_insert_child.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:58:28 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/04 10:58:28 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

void	node_insert_child(t_node *const self, t_node *const child)
{
	if (!self || !child)
		return ;
	child->next = self->next;
	if (self->next)
		self->next->prev = child;
	child->prev = self;
	self->next = child;
}
