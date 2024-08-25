/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_inputs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:29:16 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/24 15:29:16 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool player_can_move(t_map *map, t_vec2 pos, t_vec2 min, t_vec2 max)
{
	t_vec2i	v;

	if (pos.x <= min.x || pos.y <= min.y)
		return (false);
	else if (pos.x >= max.x || pos.y >= max.y)
		return (false);
	v.x = floorf(pos.x);
	v.y = floorf(pos.y);
	return (map_is_valid_position(map, v));
}

void player_move(t_player *const self, int32_t action, float_t amount)
{
    t_vec2 pos;

    pos = self->pos;
    if (action == PLAYER_MOVE_FORWARD)
    {
        pos.x += self->dir.x * amount;
        pos.y += self->dir.y * amount;
    }
    else if (action == PLAYER_MOVE_BACKWARD)
    {
        pos.x -= self->dir.x * amount;
        pos.y -= self->dir.y * amount;
    }
    else if (action == PLAYER_MOVE_LEFT)
    {
        pos.x += self->dir.y * amount;
        pos.y -= self->dir.x * amount;
    }
    else if (action == PLAYER_MOVE_RIGHT)
    {
        pos.x -= self->dir.y * amount;
        pos.y += self->dir.x * amount;
    }

    if (player_can_move(self->map, pos, self->bound_min, self->bound_max))
        self->pos = pos;
}


void player_rota(t_player *const self, int32_t action, float_t amount)
{
    float oldDirX = self->dir.x;
    float oldPlaneX = self->plane.x;

    if (action == PLAYER_ROTA_LEFT)
    {
        self->dir.x = self->dir.x * cos(amount) - self->dir.y * sin(amount);
        self->dir.y = oldDirX * sin(amount) + self->dir.y * cos(amount);

        self->plane.x = self->plane.x * cos(amount) - self->plane.y * sin(amount);
        self->plane.y = oldPlaneX * sin(amount) + self->plane.y * cos(amount);
    }
    else if (action == PLAYER_ROTA_RIGHT)
    {
        self->dir.x = self->dir.x * cos(-amount) - self->dir.y * sin(-amount);
        self->dir.y = oldDirX * sin(-amount) + self->dir.y * cos(-amount);

        self->plane.x = self->plane.x * cos(-amount) - self->plane.y * sin(-amount);
        self->plane.y = oldPlaneX * sin(-amount) + self->plane.y * cos(-amount);
    }
}

