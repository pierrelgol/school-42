/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_push_at.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 09:01:59 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/06 09:01:59 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

void	list_push_at(t_list *const self, const uintptr_t data,
		const uint64_t index)
{
	t_node	*node;

	if (!self)
		return ;
	node = node_create(data);
	list_insert_at(self, node, index);
}
