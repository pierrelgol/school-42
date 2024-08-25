/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:07:16 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/24 19:07:17 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char player_get_pos(t_player *const self, char **map, int32_t height, int32_t width)
{
	char    ch;
	int32_t y;
	int32_t x;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			ch = map[y][x];
			if (ch == 'N' || ch == 'W' || ch == 'S' || ch == 'E')
			{
				self->pos.x = roundf(x + 0.5f);
				self->pos.y = roundf(y + 0.5f);
				map[y][x] = '0';
				return (ch);
			}
			++x;
		}
		++y;
	}
	return (0);
}

void player_get_dir(t_player *const self, char dir)
{
    if (dir == 'N')
    {
        self->dir.x = 0.0f;
        self->dir.y = -1.0f;
        self->plane.x = 0.90f;
        self->plane.y = 0.0f;
    }
    else if (dir == 'S')
    {
        self->dir.x = 0.0f;
        self->dir.y = 1.0f;
        self->plane.x = -0.90f;
        self->plane.y = 0.0f;
    }
    else if (dir == 'E')
    {
        self->dir.x = 1.0f;
        self->dir.y = 0.0f;
        self->plane.x = 0.0f;
        self->plane.y = 0.90f;
    }
    else if (dir == 'W')
    {
        self->dir.x = -1.0f;
        self->dir.y = 0.0f;
        self->plane.x = 0.0f;
        self->plane.y = -0.90f;
    }
}

t_player *player_init(t_map *const map)
{
	t_player *self;
	char      dir;

	if (!map)
		return (NULL);
	self = alloc(sizeof(t_player));
	if (!self)
		return (0);
	self->plane.x = 0.0;
	self->plane.y = 0.0;
	self->bound_min = (t_vec2){.x = 0, .y = 0};
	self->bound_max = (t_vec2){.x = map->width, .y = map->height};
	dir = player_get_pos(self, map->map, map->height, map->width);
	player_get_dir(self, dir);
	self->map = map;
	return (self);
}

t_player *player_deinit(t_player *const self)
{
	if (!self)
		return (NULL);
	dealloc(self);
	return (NULL);
}
