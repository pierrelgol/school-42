/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_split_to_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:08:18 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/04 12:08:18 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

t_list	*split_to_list(char **split)
{
	t_list		*list;
	t_node		*node;
	uint64_t	size;
	uint64_t	i;

	list = list_create();
	size = split_size(split);
	i = 0;
	while (i < size)
	{
		node = node_create((uintptr_t)string_clone(split[i]));
		list_insert_back(list, node);
		++i;
	}
	return (list);
}
