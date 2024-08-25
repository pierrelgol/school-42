/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:42:25 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/24 19:42:27 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int32_t on_program_quit(void *param)
{
	t_cub3d *self;

	self = (t_cub3d *) param;
	mlx_loop_end(self->smlx->mlx);
	cub3d_deinit(self);
	exit(0);
	return (0);
}

int32_t on_keypressed(int32_t keycode, void *param)
{
	t_cub3d *self;

	self = (t_cub3d *) param;
	if (keycode == SMLX_KEY_LEFT)
		self->player->rota_x++;
	else if (keycode == SMLX_KEY_RIGHT)
		self->player->rota_x--;
	else if (keycode == SMLX_KEY_W)
		self->player->move_y--;
	else if (keycode == SMLX_KEY_S)
		self->player->move_y++;
	else if (keycode == SMLX_KEY_A)
		self->player->move_x--;
	else if (keycode == SMLX_KEY_D)
		self->player->move_x++;
	else if (keycode == SMLX_KEY_ESC)
		on_program_quit(param);
	return (0);
}

int32_t on_keyreleased(int32_t keycode, void *param)
{
	t_cub3d *self;

	self = (t_cub3d *) param;
	if (keycode == SMLX_KEY_LEFT)
		self->player->rota_x = 0;
	else if (keycode == SMLX_KEY_RIGHT)
		self->player->rota_x = 0;
	else if (keycode == SMLX_KEY_W)
		self->player->move_y = 0;
	else if (keycode == SMLX_KEY_S)
		self->player->move_y = 0;
	else if (keycode == SMLX_KEY_A)
		self->player->move_x = 0;
	else if (keycode == SMLX_KEY_D)
		self->player->move_x  = 0;
	else if (keycode == SMLX_KEY_ESC)
		on_program_quit(param);
	return (0);
}

int32_t on_mousemove(int32_t x, int32_t y, void *param)
{
	t_cub3d *self;

	self = (t_cub3d *) param;
	(void) y;
	self->player->amount = (x - WIDTH_MIDDLE) * MOUSE_ROTA_STEP;
	if (x > WIDTH_MIDDLE)
		self->player->rota_y++;		
	else if (x < WIDTH_MIDDLE)
		self->player->rota_y--;
	else
	{
		self->player->rota_y = 0;
		self->player->amount = 0;
	}
	mlx_mouse_move(self->smlx->mlx, self->smlx->win, WIDTH / 2, HEIGHT / 2);
	return (0);
}
