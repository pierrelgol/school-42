/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 19:00:46 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/23 19:00:47 by pollivie         ###   ########.fr       */
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
				self->pos.x = x;
				self->pos.y = y;
				map[y][x] = '0';
				return (ch);
			}
			++x;
		}
		++y;
	}
	return (0);
}

static void player_get_dir(t_player *const self, char dir)
{
	
	if (dir == 'N')
	{
		self->dir.x = 1.0f;
		self->dir.y = 1.0f;
	}
	else if (dir == 'S')
	{
		self->dir.x = 0.0f;
		self->dir.y = 0.0f;
	}
	else if (dir == 'E')
	{
		self->dir.x = 1.0f;
		self->dir.y = 0.0f;
	}
	else if (dir == 'W')
	{
		self->dir.x = 0.0f;
		self->dir.y = 1.0f;
	}
}

bool player_init(t_player *const self, t_map *const map)
{
	char dir;

	dir = player_get_pos(self, map->map, map->height, map->width);
	player_get_dir(self, dir);
	self->map = map;
	self->plane.x = 0.0;
	self->plane.y = 0.33f;
	self->mov_step = MOV_STEP;
	self->rot_step = ROT_STEP;
	self->bound_min = (t_vec2){.x = 0, .y = 0};
	self->bound_max = (t_vec2){.x = map->width, .y = map->height};
	return (true);
}

bool player_deinit(t_player *const self)
{
	if (!self)
		return (false);
	zeroed(self, sizeof(*self));
	return (true);
}
