/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:41:54 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/24 19:41:55 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <X11/X.h>

static void draw_texture(t_smlx_instance *self, t_ray *ray, t_smlx_texture *texture, int32_t x, t_vec2i start_end)
{
    int32_t y;
    uint32_t color;
    float tex_pos;
    float step;
    int tex_x;
    int tex_y;

    // Calculate the texture X coordinate (horizontal position on the wall hit by the ray)
    float wall_x = ray->wall_x; // Ensure this is calculated correctly in ray_compute_at()
    tex_x = (int)(wall_x * (float)(texture->width));
    if (ray->side == 0 && ray->dir.x > 0) tex_x = texture->width - tex_x - 1;
    if (ray->side == 1 && ray->dir.y < 0) tex_x = texture->width - tex_x - 1;

    // Calculate the step size and initial texture position
    step = 1.0 * texture->height / (start_end.y - start_end.x);
    tex_pos = (start_end.x - (float)self->height / 2 + ((float)start_end.y - start_end.x) / 2) * step;

    y = start_end.x;
    while (y <= start_end.y)
    {
        tex_y = (int)tex_pos & (texture->height - 1);
        tex_pos += step;

        color = smlx_get_texture_color_at(texture, (float)tex_x / texture->width, (float)tex_y / texture->height);
        smlx_draw_pixel(self, (t_vec2i){.x = x, .y = y}, color);
        ++y;
    }
}

int32_t cub3d_render(void *param)
{
    t_cub3d *self;
    t_vec2i middle;
    t_vec2i floor;
    t_vec2i ceil;
    int32_t  i;

    self = (t_cub3d *) param;
    player_update(self->player);
    i = 0;
    ceil.x = self->height / 2;
    ceil.y = self->height;
    floor.x = 0;
    floor.y = self->height / 2;
    smlx_draw_clear(self->smlx, SMLX_SOLID_BLACK);
    while (i < self->width)
    {
        ray_compute_at(self->ray, i, self->map->map);
        middle = self->ray->draw_range;
        smlx_draw_vertical(self->smlx, i, ceil, SMLX_ROSE_PINE_IRIS);
        smlx_draw_vertical(self->smlx, i, floor, SMLX_ROSE_PINE_HLLOW);
        if (self->ray->orientation == NORTH)
            draw_texture(self->smlx, self->ray, self->no_texture, i, middle);
        else if (self->ray->orientation == SOUTH)
            draw_texture(self->smlx, self->ray, self->so_texture, i, middle);
        else if (self->ray->orientation == WEST)
            draw_texture(self->smlx, self->ray, self->we_texture, i, middle);
        else if (self->ray->orientation == EAST)
            draw_texture(self->smlx, self->ray, self->ea_texture, i, middle);
        ++i;
    }
    smlx_instance_display(self->smlx);
    return (0);
}


void cub3d_start(t_cub3d *const self, t_smlx_instance *const smlx)
{
	smlx_chrono_starts(self->smlx);
	mlx_hook(smlx->win, 17, 0, on_program_quit, self);
	mlx_hook(smlx->win, KeyPress, KeyPressMask, on_keypressed, self);
	mlx_hook(smlx->win, KeyRelease, KeyReleaseMask, on_keyreleased, self);
	mlx_hook(smlx->win, MotionNotify, PointerMotionMask, on_mousemove, self);
	mlx_mouse_move(self->smlx->mlx, self->smlx->win, WIDTH / 2, HEIGHT / 2);
	mlx_loop_hook(smlx->mlx, cub3d_render, self);
	mlx_mouse_hide(smlx->mlx, smlx->win);
	mlx_loop(smlx->mlx);
}
