/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <plgol.perso@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:05:33 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/10 11:05:34 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_builtins_cd	*cd_create(t_envmap *env)
{
	t_builtins_cd	*self;

	self = memory_alloc(sizeof(t_builtins_cd));
	if (!self)
		return (NULL);
	self->env = env;
	self->cwd = getcwd(NULL, 0);
	self->pwd = envmap_get(env, "PWD");
	self->opwd = envmap_get(env, "OPWD");
	return (self);
}

bool	cd_change_directory(t_builtins_cd *self, char *target)
{
	if (access(target, F_OK) == 0)
	{
		if (chdir(target) == 0)
		{
			self->opwd = self->pwd;
			envmap_set(self->env, "OPWD", self->pwd);
			self->pwd = self->cwd;
			envmap_set(self->env, "PWD", self->cwd);
			self->cwd = string_clone(target);
			return (true);
		}
	}
	return (false);
}

t_builtins_cd	*cd_destroy(t_builtins_cd *self)
{
	if (self)
	{
		if (self->cwd)
			memory_dealloc(self->cwd);
		memory_dealloc(self);
	}
	return (NULL);
}
