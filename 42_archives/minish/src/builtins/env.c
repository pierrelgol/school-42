/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <plgol.perso@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:00:05 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/11 10:00:05 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_builtins_env	*env_create(t_envmap *env)
{
	t_builtins_env	*self;

	self = memory_alloc(sizeof(t_builtins_env));
	if (!self)
		return (NULL);
	self->env = env;
	self->it = list_iter_create(self->env->keys);
	return (self);
}

bool	env_put(t_builtins_env *self, char *variable, char *value)
{
	if (!variable || !value)
		return (false);
	envmap_set(self->env, variable, value);
	return (true);
}

bool	env_print_one(t_builtins_env *self, char *variable)
{
	char	*value;

	value = envmap_get(self->env, variable);
	if (value)
	{
		printf("%s=%s\n", variable, value);
	}
	return (false);
}

bool	env_print_all(t_builtins_env *self)
{
	char	*key;

	it_save(self->it);
	while (!it_end(self->it))
	{
		key = (char *)it_peek_curr(self->it);
		if (key)
			env_print_one(self, key);
		it_advance(self->it);
	}
	it_restore(self->it);
	return (true);
}

t_builtins_env	*env_destroy(t_builtins_env *self)
{
	if (self)
		memory_dealloc(self);
	return (NULL);
}
