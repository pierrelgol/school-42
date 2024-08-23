/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 09:49:22 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/07 09:49:22 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_resolver	*resolver_destroy(t_resolver *const self)
{
	t_node	*node;
	char	*path;

	if (!self)
		return (NULL);
	string_split_destroy(self->paths);
	node = self->path->head;
	while (node)
	{
		path = (char *)node->data;
		if (path)
			free(path);
		node = node->next;
	}
	list_destroy(self->path);
	if (self->it)
		list_iter_destroy(self->it);
	return (NULL);
}
