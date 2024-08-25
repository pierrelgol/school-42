/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:27:20 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/23 18:27:21 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_clone(t_map *const self, char **dest, char **source)
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
	dest[i] = NULL ;
}

bool	map_init(t_map *const self, t_config *const cfg)
{
	int32_t	i;

	self->height = cfg->height;
	self->width = cfg->width;
	self->map = alloc((self->height + 1 ) * sizeof(char*));
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
	return (true);
}

bool	map_is_valid_position(t_map *const self, t_vec2i pos)
{
	if (pos.x < 0 || pos.x >= self->width)
		return (false);
	if (pos.y < 0 || pos.y >= self->height)
		return (false);
	if (self->map[pos.y][pos.x] == '0')
		return (true);
	return (false);
}

bool	map_deinit(t_map *const self)
{
	if (!self)
		return (false);
	if (self->map)
		dealloc_array(self->map);
	zeroed(self, sizeof(*self));
	return (true);
}
