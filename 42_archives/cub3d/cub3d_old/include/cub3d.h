/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:17:41 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/23 13:17:42 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "common.h"
#include "slib.h"
#include "smlx.h"
#include "smlx_keysym.h"
#include <fcntl.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

#define PLAYER_MOVE_LEFT 1
#define PLAYER_MOVE_RIGHT 2
#define PLAYER_MOVE_FORWARD 3
#define PLAYER_MOVE_BACKWARD 4
#define PLAYER_ROTA_LEFT 1
#define PLAYER_ROTA_RIGHT 2
#define PLAYER_ROTA_FORWARD 3
#define PLAYER_ROTA_BACKWARD 4

// debug
void	log_info(const char *const msg);
void	log_assert(bool cond, const char *const msg);
void	log_cub3d(t_cub3d *const self, const char *const label);
void	log_map(t_map *const self);
void	log_player(t_player *const self);

// error
void panic_and_die(const char *const msg);

// parsing
bool	config_init(t_config *const self, const char *const filename);
bool	config_check(t_config *const self);
bool	config_parse(t_config *const self);
void	config_deinit(t_config *const self);

// map
bool	map_init(t_map *const self, t_config *const cfg);
bool	map_deinit(t_map *const self);
bool	map_is_valid_position(t_map *const self, t_vec2i pos);

// player
bool	player_init(t_player *const self, t_map *const map);
bool	player_deinit(t_player *const self);
void	player_move(t_player *const self, int32_t action , float_t amount);
void	player_rota(t_player *const self, int32_t action , float_t amount);

// ray
bool	ray_init(t_ray *const self);

// main
bool cub3d_init(t_cub3d *const self, const char *const filename);
bool cub3d_deinit(t_cub3d *const self);

// utils
void	dealloc_array(char **array);
int32_t	string_to_rgb(const char *const line);

// cub3d
void	cub3d_run(t_cub3d *const self, t_smlx_instance *const smlx);
void	cub3d_draw(t_cub3d *const self, t_player *const player, t_ray *const ray, t_map *const map);


#endif
