/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:45:22 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/24 18:45:23 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void map_clone(t_map *const self, char **dest, char **source)
{
	int32_t i;
	int32_t j;

	i = 0;
	while (i < self->height)
	{
		j = 0;
		while (source[i][j] && is_spaces(source[i][j]))
			dest[i][j++] = '1';
		while (source[i][j])
		{
			if (is_spaces(source[i][j]))
				dest[i][j] = '1';
			else
				dest[i][j] = source[i][j];
			++j;
		}
		while (j < self->width)
			dest[i][j++] = '1';
		dest[i][j] = 0x00;
		++i;
	}
	dest[i] = NULL;
}

t_map *map_init(t_config *const cfg)
{
	t_map *self;
	int32_t i;

	if (!cfg)
		return (NULL);
	self = alloc(sizeof(t_map));
	if (!self)
		return (NULL);
	self->height = cfg->height;
	self->width = cfg->width;
	self->map = alloc((self->height + 1) * sizeof(char *));
	i = 0;
	while (i < self->height)
	{
		self->map[i] = alloc((self->width + 1));
		if (!self->map[i])
			return (false);
		filled(self->map[i], '1', self->width);
		++i;
	}
	map_clone(self, self->map, &cfg->file_lines[6]);
	return (self);
}

t_map *map_deinit(t_map *const self)
{
	if (!self)
		return (NULL);
	if (self->map)
		dealloc_array(self->map);
	dealloc(self);
	return (NULL);
}
