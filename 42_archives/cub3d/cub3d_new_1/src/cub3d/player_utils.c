/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:42:07 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/24 19:42:08 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool player_can_move(t_map *map, t_vec2 pos, t_vec2 min, t_vec2 max)
{
	t_vec2i v;

	if (pos.x <= min.x || pos.y <= min.y)
		return (false);
	else if (pos.x >= max.x || pos.y >= max.y)
		return (false);
	v.x = (int)pos.x;
	v.y = (int)pos.y;
	if (pos.x < 0 || pos.x >= map->width)
		return (false);
	if (pos.y < 0 || pos.y >= map->height)
		return (false);
	if (map->map[v.y][v.x] == '0')
		return (true);
	return (false);
}

static void player_move(t_player *const self, float_t amount)
{
	t_vec2 pos;

	pos = self->pos;
	if (self->move_y < 0)
	{
		pos.x += self->dir.x * amount;
		pos.y += self->dir.y * amount;
	}
	if (self->move_y > 0)
	{
		pos.x -= self->dir.x * amount;
		pos.y -= self->dir.y * amount;
	}
	if (self->move_x < 0)
	{
		pos.x += self->dir.y * amount;
		pos.y -= self->dir.x * amount;
	}
	if (self->move_x > 0)
	{
		pos.x -= self->dir.y * amount;
		pos.y += self->dir.x * amount;
	}
	if (player_can_move(self->map, pos, self->bound_min, self->bound_max))
		self->pos = pos;
}

static void player_rotate(t_player *const self, float_t amount)
{
	float old_dir_x = self->dir.x;
	float old_plane_x = self->plane.x;

	amount = self->rota_x * amount;
	if (self->rota_x > 0)
	{
		self->dir.x = self->dir.x * cos(amount) - self->dir.y * sin(amount);
		self->dir.y = old_dir_x * sin(amount) + self->dir.y * cos(amount);
		self->plane.x = self->plane.x * cos(amount) - self->plane.y * sin(amount);
		self->plane.y = old_plane_x * sin(amount) + self->plane.y * cos(amount);
		// self->rota_x--;
	}
	if (self->rota_x < 0)
	{
		self->dir.x = self->dir.x * cos(amount) - self->dir.y * sin(amount);
		self->dir.y = old_dir_x * sin(amount) + self->dir.y * cos(amount);
		self->plane.x = self->plane.x * cos(amount) - self->plane.y * sin(amount);
		self->plane.y = old_plane_x * sin(amount) + self->plane.y * cos(amount);
		// self->rota_x++;
	}
}

static void player_mouse_rotate(t_player *const self, float_t amount)
{
	float old_dir_x = self->dir.x;
	float old_plane_x = self->plane.x;

	self->dir.x = self->dir.x * cos(amount) - self->dir.y * sin(amount);
	self->dir.y = old_dir_x * sin(amount) + self->dir.y * cos(amount);
	self->plane.x = self->plane.x * cos(amount) - self->plane.y * sin(amount);
	self->plane.y = old_plane_x * sin(amount) + self->plane.y * cos(amount);
}

void player_update(t_player *const self)
{
	int64_t time_now = smlx_timestamp();
	int64_t delta = time_now - self->time_last_move;
	float   delta_time = delta / 1000.0;
	if (self->move_x != 0 || self->move_y != 0)
		player_move(self, MOV_STEP - MOV_STEP * delta_time);
	if (self->rota_x != 0)
		player_rotate(self, ROT_STEP - ROT_STEP * delta_time);
	if (self->rota_y != 0)
		player_mouse_rotate(self, self->amount);
	self->time_last_move = time_now;
}
