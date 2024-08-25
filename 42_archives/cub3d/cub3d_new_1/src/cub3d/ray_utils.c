/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:36:53 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/24 19:36:53 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static inline void ray_update_2(t_ray *const self)
{
	if (self->dir.x < 0)
	{
		self->step_x = -1;
		self->dist_side.x = (self->pos.x - self->map_x) * self->dist_delt.x;
	}
	else
	{
		self->step_x = 1;
		self->dist_side.x = (self->map_x + 1.0 - self->pos.x) * self->dist_delt.x;
	}
	if (self->dir.y < 0)
	{
		self->step_y = -1;
		self->dist_side.y = (self->pos.y - self->map_y) * self->dist_delt.y;
	}
	else
	{
		self->step_y = 1;
		self->dist_side.y = (self->map_y + 1.0 - self->pos.y) * self->dist_delt.y;
	}
}

static inline void ray_start(t_ray *const self, int32_t x)
{
	t_player *p = self->player;

	self->camera_x = 2 * x / (double) WIDTH - 1;
	self->pos.x = p->pos.x;
	self->pos.y = p->pos.y;
	self->dir.x = p->dir.x + p->plane.x * self->camera_x;
	self->dir.y = p->dir.y + p->plane.y * self->camera_x;
	self->map_x = (int32_t) (self->pos.x);
	self->map_y = (int32_t) (self->pos.y);

	self->dist_delt.x = (self->dir.x == 0) ? 1e30 : fabs(1 / self->dir.x);
	self->dist_delt.y = (self->dir.y == 0) ? 1e30 : fabs(1 / self->dir.y);
	ray_update_2(self);
}

static inline void ray_launch(t_ray *const self, char **map)
{
	self->hit = 0;
	while (self->hit == 0)
	{
		if (self->dist_side.x < self->dist_side.y)
		{
			self->dist_side.x += self->dist_delt.x;
			self->map_x += self->step_x;
			self->side = 0;
		}
		else
		{
			self->dist_side.y += self->dist_delt.y;
			self->map_y += self->step_y;
			self->side = 1;
		}
		if (map[self->map_y][self->map_x] == '1')
			self->hit = 1;
	}
}

static inline void ray_end(t_ray *const self, char **map)
{
    if (self->side == 0)
    {
        self->dist_perp = (self->map_x - self->pos.x + (1 - self->step_x) / 2) / self->dir.x;
        self->wall_x = self->pos.y + self->dist_perp * self->dir.y;
    }
    else
    {
        self->dist_perp = (self->map_y - self->pos.y + (1 - self->step_y) / 2) / self->dir.y;
        self->wall_x = self->pos.x + self->dist_perp * self->dir.x;
    }
    self->wall_x -= floor(self->wall_x); // Ensure wall_x is in the range [0, 1]

    self->line_height = (int) (self->height / self->dist_perp);
    self->draw_range.x = -self->line_height / 2 + self->height / 2;
    if (self->draw_range.x < 0)
        self->draw_range.x = 0;
    self->draw_range.y = self->line_height / 2 + self->height / 2;
    if (self->draw_range.y >= self->height)
        self->draw_range.y = self->height - 1;

    self->color = SMLX_SOLID_WHITE;
    if (map[self->map_y][self->map_x] == '1')
    {
        if (self->side == 0 && self->dir.x > 0)
            self->orientation = NORTH;
        else if (self->side == 0 && self->dir.x < 0)
            self->orientation = SOUTH;
        else if (self->side == 1 && self->dir.y > 0)
            self->orientation = EAST;
        else
            self->orientation = WEST;
    }
}


void ray_compute_at(t_ray *const self, int32_t x, char **map)
{
	ray_start(self, x);
	ray_launch(self, map);
	ray_end(self, map);
}
