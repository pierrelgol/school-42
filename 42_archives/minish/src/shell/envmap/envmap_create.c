/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envmap_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:31:09 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/04 15:31:10 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_envmap	*envmap_init(t_envmap *const self, char **envp)
{
	uint64_t	index;
	uint64_t	i;
	char		*k;
	char		*v;

	i = 0;
	while (envp[i])
	{
		index = string_index_of(envp[i], '=');
		k = string_nclone(envp[i], index);
		v = string_clone(&envp[i][index + 1]);
		hashmap_put(self->map, k, (uintptr_t)v);
		list_push_back(self->keys, (uintptr_t)k);
		list_push_back(self->values, (uintptr_t)v);
		i += 1;
	}
	return (self);
}

t_envmap	*envmap_create(char **envp)
{
	t_envmap	*self;

	self = (t_envmap *)memory_alloc(sizeof(t_envmap));
	if (!self)
		return (NULL);
	self->envp = envp;
	self->keys = list_create();
	if (!self->keys)
		return (envmap_destroy(self));
	self->values = list_create();
	if (!self->values)
		return (envmap_destroy(self));
	self->map = hashmap_create(512);
	if (!self->map)
		return (envmap_destroy(self));
	return (envmap_init(self, envp));
}
