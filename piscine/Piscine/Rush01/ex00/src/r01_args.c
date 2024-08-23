/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r01_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:01:46 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/17 20:01:49 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/r01_args.h"
#include "../lib/r01_core.h"

t_args	*args_init(char *args)
{
	t_args	*self;

	if (!args)
		return (NULL);
	self = (t_args *)malloc(sizeof(t_args) * 1);
	if (!self)
		return (NULL);
	*self = (t_args){0, 0, 0, 0, true, NULL};
	if (args_parse(self, args) == false)
		return (args_dispose(self));
	self->inputs = (int *)malloc(sizeof(int) * self->args_count);
	if (args_fill(self, args) == false)
		return (args_dispose(self));
	if (!self->inputs)
		return (args_dispose(self));
	return (self);
}

bool	args_fill(t_args *self, char *args)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (args[i] != '\0')
	{
		if (args[i] >= '0' && args[i] <= '9')
			self->inputs[j++] = args[i] - '0';
		++i;
	}
	return (true);
}

bool	args_parse(t_args *self, char *args)
{
	int	i;

	i = 0;
	self->args_min = args[i] - '0';
	while (args[i] != '\0' && self->args_valid == true)
	{
		if (args[i] >= '0' && args[i] <= '9')
		{
			self->args_count += 1;
			if ((args[i] - '0') > self->args_max)
				self->args_max = args[i] - '0';
			if ((args[i] - '0') < self->args_min)
				self->args_min = args[i] - '0';
			++i;
		}
		else if ((args[i] == ' ') || (args[i] >= 9 && args[i] <= 13))
			++i;
		else
			self->args_valid = false;
	}
	return (self->args_valid);
}

t_args	*args_dispose(t_args *self)
{
	if (self)
	{
		if (self->inputs)
			free(self->inputs);
		free(self);
	}
	return (NULL);
}
