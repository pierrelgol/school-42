/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <plgol.perso@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:05:19 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/10 11:05:20 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_builtins_unset	*unset_create(t_envmap *env)
{
	t_builtins_unset	*self;

	self = memory_alloc(sizeof(t_builtins_unset));
	if (!self)
		return (NULL);
	self->env = env;
	return (self);
}

bool	unset_unset(t_builtins_unset *self, char *k)
{
	char	*result;

	if (!k)
		return (false);
	result = (char *)envmap_get(self->env, k);
	if (result)
	{
		memory_dealloc(result);
		return (true);
	}
	return (false);
}

t_builtins_unset	*unset_destroy(t_builtins_unset *self)
{
	if (self)
		memory_dealloc(self);
	return (NULL);
}
