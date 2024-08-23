/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r01_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:02:05 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/17 20:02:08 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/r01_map.h"

t_map	*map_init(t_args *in)
{
	t_map	*self;

	if (!in)
		return (NULL);
	self = (t_map *)malloc(sizeof(t_map) * 1);
	if (!self)
		return (NULL);
	*self = (t_map){0, 0, 0, true, NULL};
	self->map_dim = in->args_max;
	if (map_map(self, in) == false)
		return (map_dispose(self));
	return (self);
}

bool	map_map(t_map *self, t_args *in)
{
	int	row;
	int	col;
	int	*value;

	row = 0;
	value = in->inputs;
	self->map = (int **)malloc(sizeof(int *) * self->map_dim);
	if (self->map)
	{
		while (row < self->map_dim)
		{
			self->map[row] = (int *)malloc(sizeof(int) * self->map_dim);
			if (self->map[row])
			{
				col = 0;
				while (col < self->map_dim)
					self->map[row][col++] = *value++;
			}
			else
				self->map_valid = false;
			++row;
		}
	}
	return (self->map_valid);
}

t_map	*map_dispose(t_map *self)
{
	int	i;

	i = 0;
	if (self)
	{
		if (self->map)
		{
			while (i < self->map_dim)
				free(self->map[i++]);
			free(self->map);
		}
		free(self);
	}
	return (NULL);
}
