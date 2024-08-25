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

#define WIDTH 1280
#define HEIGHT 720
#define WIDTH_MIDDLE ((float)WIDTH / 2.0f)
#define MOV_STEP 0.1f
#define ROT_STEP 0.1f
#define MAX_DISTANCE 20.0
#define PLAYER_NOOP 0
#define PLAYER_MOVE_LEFT 1
#define PLAYER_MOVE_RIGHT 2
#define PLAYER_MOVE_FORWARD 3
#define PLAYER_MOVE_BACKWARD 4
#define PLAYER_ROTA_LEFT 5
#define PLAYER_ROTA_RIGHT 6
#define PLAYER_ROTA_FORWARD 7
#define PLAYER_ROTA_BACKWARD 8
#define MOUSE_ROTA_STEP (0.005f)
#define NORTH 1
#define SOUTH 2
#define EAST 3
#define WEST 4

// debug
void log_info(const char *const msg);
void log_assert(bool cond, const char *const msg);

// error
void panic_and_die(const char *const msg);

t_cub3d *cub3d_deinit(t_cub3d *const self);
t_cub3d *cub3d_init(const char *filename);
void cub3d_start(t_cub3d *const self, t_smlx_instance *const smlx);
int32_t cub3d_render(void *param);

//hooks
int32_t on_program_quit(void *param);
int32_t on_keypressed(int32_t keycode, void *param);
int32_t on_keyreleased(int32_t keycode, void *param);
int32_t on_mousemove(int32_t x, int32_t y, void *param);

// parsing
t_config *config_init(const char *const filename);
bool      config_check(t_config *const self);
bool      config_parse(t_config *const self);
t_config *config_deinit(t_config *const self);

// map
t_map *map_init(t_config *const cfg);
t_map *map_deinit(t_map *const self);

// player
t_player *player_init(t_map *const map);
t_player *player_deinit(t_player *const self);
void	player_update(t_player *const self);

// ray
t_ray *ray_init(t_player *const player, t_map *const map);
t_ray *ray_deinit(t_ray *const self);
void   ray_compute_at(t_ray *const self, int32_t x, char **map);

// utils
void    dealloc_array(char **array);
int32_t string_to_rgb(const char *const line);
void	print_fps(int64_t delta_time);

#endif
