/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 09:44:49 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/07 09:44:49 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_resolver	*resolver_create(t_list *token_pool, t_envmap *envmap)
{
	t_resolver	*self;

	self = memory_alloc(sizeof(t_resolver));
	if (!self)
		return (NULL);
	self->token_pool = token_pool;
	self->input = NULL;
	self->map = envmap;
	self->paths = string_tokenize(envmap_get(envmap, "PATH"), ":");
	self->path = split_to_list(self->paths);
	self->it = list_iter_create(self->path);
	return (self);
}
