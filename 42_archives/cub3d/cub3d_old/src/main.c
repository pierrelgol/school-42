/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:17:26 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/23 13:17:27 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool cub3d_init(t_cub3d *const self, const char *const filename)
{
	if (!config_init(&self->config, filename))
		return (false);
	if (!map_init(&self->map, &self->config))
		return (false);
	if (!player_init(&self->player, &self->map))
		return (false);
	self->smlx = smlx_instance_create(WIDTH, HEIGHT, "cub3d");
	if (!self->smlx)
		return (false);
	return (true);
}

bool cub3d_deinit(t_cub3d *const self)
{
	if (self->smlx)
		smlx_instance_destroy(self->smlx);
	config_deinit(&self->config);
	player_deinit(&self->player);
	map_deinit(&self->map);
	dealloc(self);
	return (true);
}


int main(int32_t argc, char **argv)
{
	
	t_cub3d *self;

	self = alloc(sizeof(t_cub3d));
	zeroed(self, sizeof(t_cub3d));
	if (argc != 2 || !string_ends_with_sequence(argv[1], ".cub"))
		panic_and_die("invalid arguments");

	if (!cub3d_init(self, argv[1]))
		panic_and_die("initialization failed");
	log_cub3d(self, "main");
	log_map(&self->map);
	cub3d_run(self, self->smlx);
	dealloc(self);
	// cub3d_deinit(&self);
	return (0);
}
