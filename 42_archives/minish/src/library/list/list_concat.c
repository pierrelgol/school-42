/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_concat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 19:39:42 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/06 19:39:43 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

void	list_concat(t_list *const dest, t_list *const src)
{
	t_node	*node;

	if (!dest || !src || list_is_empty(src))
		return ;
	while (!list_is_empty(src))
	{
		node = list_remove_front(src);
		list_insert_back(dest, node);
	}
}
