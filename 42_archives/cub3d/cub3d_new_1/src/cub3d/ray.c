/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:16:48 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/24 19:16:49 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_ray *ray_init(t_player *const player, t_map *const map)
{
	t_ray *self;

	if (!player || !map)
		return (NULL);
	self = alloc(sizeof(t_ray));
	if (!self)
		return (NULL);
	self->map = map;
	self->player = player;
	return (self);
}


t_ray *ray_deinit(t_ray *const self)
{
	if (!self)
		return (NULL);
	dealloc(self);
	return (NULL);
}
