/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <plgol.perso@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:05:51 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/10 11:05:52 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_builtins_echo	*echo_create(t_envmap *env)
{
	t_builtins_echo	*self;

	self = memory_alloc(sizeof(t_builtins_echo));
	if (!self)
		return (NULL);
	self->env = env;
	self->fd = STDOUT_FILENO;
	return (self);
}

bool	echo_print(t_builtins_echo *self, char *message, bool flag)
{
	if (message && !flag)
	{
		(void)self;
		printf("%s\n", message);
		return (true);
	}
	return (false);
}

t_builtins_echo	*echo_destroy(t_builtins_echo *self)
{
	if (self)
		memory_dealloc(self);
	return (NULL);
}
