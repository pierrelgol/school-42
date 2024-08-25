/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:03:17 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/24 16:03:18 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void view_changed(t_cub3d *self)
{
	double    temp_x;
	double    rot_speed;

	rot_speed = 0.0;
	if (self->player.moved_x)
		rot_speed = self->player.rot_step * 1;
	if (self->player.moved_y)
		rot_speed = self->player.rot_step * -1;
	temp_x = self->player.dir.x;
	self->player.dir.x = self->player.dir.x * cos(rot_speed) - self->player.dir.y * sin(rot_speed);
	self->player.dir.y = temp_x * sin(rot_speed) + self->player.dir.y * cos(rot_speed);
	temp_x = self->player.plane.x;
	self->player.plane.x = self->player.plane.x * cos(rot_speed) - self->player.plane.y * sin(rot_speed);
	self->player.plane.y = temp_x * sin(rot_speed) + self->player.plane.y * cos(rot_speed);
}

int handle_mouvement(int x, int y, t_cub3d *self)
{
	double    rotspeed;
	t_player *p;
	double    tmp_x;

	p = &self->player;
	(void) y;
	if (x > WIDTH / 2)
		rotspeed = (p->rot_step * (0.01 * ((float) WIDTH / 2 - x)) / 4);
	else if (x < WIDTH / 2)
		rotspeed = -p->rot_step * (0.01 * (x - ((float) WIDTH / 2))) / 4;
	else
		return 0;

	// Rotate direction vector
	tmp_x = p->dir.x;
	p->dir.x = p->dir.x * cos(rotspeed) - p->dir.y * sin(rotspeed);
	p->dir.y = tmp_x * sin(rotspeed) + p->dir.y * cos(rotspeed);

	// Rotate camera plane
	tmp_x = p->plane.x;
	p->plane.x = p->plane.x * cos(rotspeed) - p->plane.y * sin(rotspeed);
	p->plane.y = tmp_x * sin(rotspeed) + p->plane.y * cos(rotspeed);

	mlx_mouse_move(self->smlx->mlx, self->smlx->win, WIDTH / 2, HEIGHT / 2);
	return 0;
}

int32_t on_program_quit(void *param)
{
	t_cub3d *self;

	self = (t_cub3d *) param;
	mlx_loop_end(self->smlx->mlx);
	cub3d_deinit(self);
	exit(0);
	return (0);
}

void cub3d_draw(t_cub3d *const self, t_player *const player, t_ray *const ray, t_map *const map)
{
	double   camera_x;
	int32_t  line_height;
	int32_t  draw_start;
	int32_t  draw_end;
	uint32_t color;
	int32_t  x;

	(void) (self);
	(void) (camera_x);
	(void) (line_height);
	(void) (draw_start);
	(void) (draw_end);
	(void) (color);
	(void) (x);
	(void) (player);
	(void) (ray);
	(void) (map);

	x = 0;
	while (x < WIDTH)
	{
		camera_x = 2 * x / (double) WIDTH - 1;
		ray->pos.x = player->pos.x;
		ray->pos.y = player->pos.y;
		ray->dir.x = player->dir.x + player->plane.x * camera_x;
		ray->dir.y = player->dir.y + player->plane.y * camera_x;
		ray->map_x = (int32_t) floorf(ray->pos.x);
		ray->map_y = (int32_t) floorf(ray->pos.y);

		if (ray->dir.x == 0)
			ray->dist_delt.x = 1e30;
		else
			ray->dist_delt.x = fabsf(1 / ray->dir.x);

		if (ray->dir.y == 0)
			ray->dist_delt.y = 1e30;
		else
			ray->dist_delt.y = fabsf(1 / ray->dir.y);

		if (ray->dir.x < 0)
		{
			ray->step_x = -1;
			ray->dist_side.x = (ray->pos.x - ray->map_x) * ray->dist_delt.x;
		}
		else
		{
			ray->step_x = 1;
			ray->dist_side.x = (ray->map_x + 1.0 - ray->pos.x) * ray->dist_delt.x;
		}
		if (ray->dir.y < 0)
		{
			ray->step_y = -1;
			ray->dist_side.y = (ray->pos.y - ray->map_y) * ray->dist_delt.y;
		}
		else
		{
			ray->step_y = 1;
			ray->dist_side.y = (ray->map_y + 1.0 - ray->pos.y) * ray->dist_delt.y;
		}

		ray->hit = 0;
		while (ray->hit == 0)
		{
			if (ray->dist_side.x < ray->dist_side.y)
			{
				ray->dist_side.x += ray->dist_delt.x;
				ray->map_x += ray->step_x;
				ray->side = 0;
			}
			else
			{
				ray->dist_side.y += ray->dist_delt.y;
				ray->map_y += ray->step_y;
				ray->side = 1;
			}
			if (map->map[ray->map_y][ray->map_x] == '1')
				ray->hit = 1;
		}

		if (ray->side == 0)
			ray->dist_perp =
			    (ray->map_x - ray->pos.x + (1 - ray->step_x) / 2) / ray->dir.x;
		else
			ray->dist_perp =
			    (ray->map_y - ray->pos.y + (1 - ray->step_y) / 2) / ray->dir.y;

		line_height = (int) (HEIGHT / ray->dist_perp);

		draw_start = -line_height / 2 + HEIGHT / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_height / 2 + HEIGHT / 2;
		if (draw_end >= HEIGHT)
			draw_end = HEIGHT - 1;

		switch (map->map[ray->map_y][ray->map_x])
		{
		case '1':
			color = SMLX_SOLID_RED;
			break; // Red
		default:
			color = SMLX_SOLID_WHITE;
			break; // White
		}

		color = 0xFFFFFF;
		switch (map->map[ray->map_y][ray->map_x])
		{
		case '1':
			if (ray->side == 0 && ray->dir.x > 0)
				color = 0xFF0000; // Red for east-facing walls
			else if (ray->side == 0 && ray->dir.x < 0)
				color = 0x00FF00; // Green for west-facing walls
			else if (ray->side == 1 && ray->dir.y > 0)
				color = 0x0000FF; // Blue for south-facing walls
			else
				color = 0xFFFF00; // Yellow for north-facing walls
			break;
		default:
			color = 0xFFFFFF; // White for other types
			break;
		}
		if (ray->side == 1)
		{
			color = color / 2;
		}
		smlx_draw_vertical(self->smlx, x, (t_vec2i){.x = draw_start, .y = draw_end}, color);
		++x;
	}
}

// void cub3d_redraw(t_cub3d *const self)
// {
// }

int32_t on_keypress(int32_t keycode, void *param)
{
	t_cub3d *self;

	self = (t_cub3d *) param;
	printf("keycode = %d\n", keycode);
	if (keycode == SMLX_KEY_W)
		player_move(&self->player, PLAYER_MOVE_FORWARD, 0.2f);
	else if (keycode == SMLX_KEY_S)
		player_move(&self->player, PLAYER_MOVE_BACKWARD, 0.2f);
	else if (keycode == SMLX_KEY_A)
		player_move(&self->player, PLAYER_MOVE_LEFT, 0.2f);
	else if (keycode == SMLX_KEY_D)
		player_move(&self->player, PLAYER_MOVE_RIGHT, 0.2f);
	else if (keycode == SMLX_KEY_E)
		player_rota(&self->player, PLAYER_ROTA_LEFT, 0.03f);
	else if (keycode == SMLX_KEY_Q)
		player_rota(&self->player, PLAYER_ROTA_RIGHT, 0.03f);
	else if (keycode == SMLX_KEY_ESC)
		on_program_quit(self);
	return (0);
}

int32_t on_keyrelease(int32_t keycode, void *param)
{
	t_cub3d *self;

	self = (t_cub3d *) param;
	printf("keycode = %d\n", keycode);
	if (keycode == SMLX_KEY_W)
		player_move(&self->player, PLAYER_MOVE_FORWARD, 0.2f);
	else if (keycode == SMLX_KEY_S)
		player_move(&self->player, PLAYER_MOVE_BACKWARD, 0.2f);
	else if (keycode == SMLX_KEY_A)
		player_move(&self->player, PLAYER_MOVE_LEFT, 0.2f);
	else if (keycode == SMLX_KEY_D)
		player_move(&self->player, PLAYER_MOVE_RIGHT, 0.2f);
	else if (keycode == SMLX_KEY_E)
		player_rota(&self->player, PLAYER_ROTA_LEFT, 0.03f);
	else if (keycode == SMLX_KEY_Q)
		player_rota(&self->player, PLAYER_ROTA_RIGHT, 0.03f);
	else if (keycode == SMLX_KEY_ESC)
		on_program_quit(self);
	return (0);
}

int32_t cub3d_loop(void *param)
{
	t_cub3d *self;

	self = (t_cub3d*)param;
	view_changed(self);
	smlx_draw_clear(self->smlx, SMLX_SOLID_BLACK);
	cub3d_draw(self, &self->player, &self->ray, &self->map);
	smlx_instance_display(self->smlx);
	return (0);
}

void cub3d_run(t_cub3d *const self, t_smlx_instance *const smlx)
{
	mlx_mouse_hide(smlx->mlx, smlx->win);
	mlx_mouse_move(smlx->mlx, smlx->win, WIDTH / 2, HEIGHT / 2);
	mlx_mouse_hook(smlx->win, handle_mouvement, self);
	mlx_key_hook(smlx->win, on_keypress, (void *) self);
	mlx_hook(smlx->win, 17, 9, on_program_quit, (void *) self);
	mlx_loop_hook(smlx->mlx, cub3d_loop, self);
	mlx_loop(smlx->mlx);
	mlx_mouse_show(smlx->mlx, smlx->win);
}
