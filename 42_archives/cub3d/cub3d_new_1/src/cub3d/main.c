/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:45:19 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/24 18:45:19 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_cub3d *cub3d_deinit(t_cub3d *const self)
{
	if (!self)
		return (NULL);
	smlx_texture_destroy(self->smlx, self->no_texture);
	smlx_texture_destroy(self->smlx, self->so_texture);
	smlx_texture_destroy(self->smlx, self->we_texture);
	smlx_texture_destroy(self->smlx, self->ea_texture);
	if (self->config)
		self->config = config_deinit(self->config);
	if (self->map)
		self->map = map_deinit(self->map);
	if (self->player)
		self->player = player_deinit(self->player);
	if (self->ray)
		self->ray = ray_deinit(self->ray);
	if (self->smlx)
		self->smlx = smlx_instance_destroy(self->smlx);
	dealloc(self);
	exit(0);
	return (NULL);
}

t_cub3d *cub3d_init(const char *filename)
{
	t_cub3d *self;

	if (!filename)
		return (NULL);
	self = alloc(sizeof(t_cub3d));
	if (!self)
		return (NULL);
	self->config = config_init(filename);
	self->map = map_init(self->config);
	self->player = player_init(self->map);
	self->ray = ray_init(self->player, self->map);
	self->smlx = smlx_instance_create(WIDTH, HEIGHT, "cub3d");
	if (!self->config || !self->map || !self->player || !self->ray || !self->smlx)
		return (cub3d_deinit(self));
	self->no_texture = smlx_texture_create(self->smlx, self->config->path_north_texture, 1);
	self->so_texture = smlx_texture_create(self->smlx, self->config->path_south_texture, 2);
	self->we_texture = smlx_texture_create(self->smlx, self->config->path_west_texture, 3);
	self->ea_texture = smlx_texture_create(self->smlx, self->config->path_east_texture, 4);
	self->width = WIDTH;
	self->height = HEIGHT;
	self->ray->height = HEIGHT;
	return (self);
}

int32_t main(int32_t argc, char **argv)
{
	t_cub3d *self;

	if (argc == 2 && string_ends_with_sequence(argv[1], ".cub"))
	{
		self = cub3d_init(argv[1]);
		smlx_set_target_fps(self->smlx, 240);
		cub3d_start(self, self->smlx);
	}
	return (0);
}
