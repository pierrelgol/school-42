/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <plgol.perso@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:05:14 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/10 11:05:14 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_builtins_export	*export_create(t_envmap *env)
{
	t_builtins_export	*self;

	self = memory_alloc(sizeof(t_builtins_export));
	if (!self)
		return (NULL);
	self->env = env;
	return (self);
}

bool	export_export(t_builtins_export *self, char *k, char *v)
{
	if (!k || !v)
		return (false);
	envmap_set(self->env, k, v);
	return (true);
}

t_builtins_export	*export_destroy(t_builtins_export *self)
{
	if (self)
		memory_dealloc(self);
	return (NULL);
}
