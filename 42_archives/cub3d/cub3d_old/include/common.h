/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 16:29:31 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/21 16:29:32 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
#define COMMON_H

#include <fcntl.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define WIDTH 1280
#define HEIGHT 720
#define MOV_STEP 0.1f
#define ROT_STEP 0.01f

#define SMLX_SOLID_WHITE 0xFFFFFFFF
#define SMLX_SOLID_BLACK 0x00000000
#define SMLX_SOLID_BLUE 0x000000FF
#define SMLX_SOLID_RED 0xFF0000FF
#define SMLX_SOLID_GREEN 0x00FF00FF
#define SMLX_SOLID_YELLOW 0xFFFF00FF
#define SMLX_SOLID_CYAN 0x00FFFFFF
#define SMLX_SOLID_MAGENTA 0xFF00FFFF
#define SMLX_SOLID_ORANGE 0xFFA500FF
#define SMLX_SOLID_PURPLE 0x800080FF
#define SMLX_SOLID_GRAY 0x808080FF
#define SMLX_SOLID_SILVER 0xC0C0C0FF
#define SMLX_SOLID_MAROON 0x800000FF
#define SMLX_SOLID_OLIVE 0x808000FF
#define SMLX_SOLID_LIME 0x00FF00FF
#define SMLX_SOLID_TEAL 0x008080FF
#define SMLX_SOLID_NAVY 0x000080FF
#define SMLX_SOLID_FUCHSIA 0xFF00FFFF
#define SMLX_SOLID_AQUA 0x00FFFFFF
#define NOTFOUND (9223372036854775807)

typedef struct s_list              t_list;
typedef struct s_node              t_node;
typedef struct s_entry             t_entry;
typedef struct s_hashmap           t_hashmap;
typedef struct s_bitset            t_bitset;
typedef struct s_smlx_bresenham    t_mlx_bresenham;
typedef struct s_smlx_instance     t_smlx_instance;
typedef struct s_smlx_event        t_smlx_event;
typedef struct s_smlx_frame_buffer t_smlx_frame_buffer;
typedef struct s_smlx_texture      t_smlx_texture;
typedef struct s_player            t_player;
typedef struct s_cub3d             t_cub3d;
typedef struct s_vec2              t_vec2;
typedef struct s_config            t_config;
typedef struct s_map_texture       t_map_texture;
typedef void                      *t_smlx_handle;
typedef bool (*t_predicate)(int32_t ch);

struct __attribute__((aligned(8))) s_node
{
	struct s_node *next;
	struct s_node *prev;
	uintptr_t      data;
};

struct __attribute__((aligned(8))) s_list
{
	t_node  *head;
	t_node  *tail;
	uint64_t size;
};

struct __attribute__((aligned(8))) s_entry
{
	char     *key;
	uintptr_t value;
};

struct __attribute__((aligned(8))) s_hashmap
{
	uint64_t size;
	uint64_t capacity;
	t_entry *body;
};

struct __attribute__((aligned(8))) s_smlx_texture
{
	t_smlx_handle *img;
	int32_t        id;
	int32_t        bpp;
	int32_t        size;
	int32_t        endiant;
	int32_t        height;
	int32_t        width;
	uint8_t       *data;
};

struct __attribute__((aligned(8))) s_smlx_bresenham
{
	int32_t dx;
	int32_t dy;
	int32_t sx;
	int32_t sy;
	int32_t err;
	int32_t e2;
};

typedef struct __attribute__((aligned(8))) s_vec2i
{
	int32_t x;
	int32_t y;
} t_vec2i;

struct __attribute__((aligned(8))) s_smlx_frame_buffer
{
	t_smlx_handle *img[3];
	int32_t        fid[3];
	int32_t        height[3];
	int32_t        width[3];
	int32_t        bpp[3];
	int32_t        size[3];
	int32_t        endian[3];
	uint8_t       *data[3];
};

struct __attribute__((aligned(8))) s_smlx_instance
{
	t_smlx_handle *mlx;
	int32_t        height;
	int32_t        width;

	t_smlx_handle *win;
	char          *title;

	t_smlx_handle *img;
	int32_t        fid;
	int32_t        bpp;
	int32_t        size;
	int32_t        endian;
	uint8_t       *data;

	bool    render_ready;
	int64_t time_last_ms;
	int64_t time_trgt_ms;
	int64_t time_prev_ms;
	int64_t time_curr_ms;
	int64_t time_delt_ms;
	int64_t frame_counter;
	int64_t frame_rendered;

	int32_t             frame_buffer_lvl;
	t_smlx_frame_buffer frame_buffer;
};

typedef enum e_texture_id
{
	NORTH_TEXTURE,
	SOUTH_TEXTURE,
	EAST_TEXTURE,
	WEST_TEXTURE,

} t_texture_id;

struct __attribute__((aligned(8))) s_vec2
{
	float x;
	float y;
};

typedef struct __attribute__((aligned(8))) s_map
{
	int32_t width;
	int32_t height;
	char  **map;
} t_map;

typedef struct __attribute__((aligned(8))) s_player
{
	t_vec2 bound_min;
	t_vec2 bound_max;
	t_vec2 pos;
	t_vec2 dir;
	t_vec2 plane;
	double  mov_step;
	double  rot_step;
	t_map *map;
	bool   moved_y;
	bool   moved_x;
} t_player;

typedef struct __attribute__((aligned(8))) s_ray
{
	t_vec2   pos;
	t_vec2   dir;
	t_vec2   dist_side;
	t_vec2   dist_delt;
	double_t dist_perp;
	int32_t  step_x;
	int32_t  step_y;
	int32_t  map_x;
	int32_t  map_y;
	int32_t  hit;
	int32_t  side;
} t_ray;

typedef struct __attribute__((aligned(8))) s_config
{
	int32_t map_start;
	int32_t width;
	int32_t height;
	char   *file_buffer;
	char  **file_lines;

	char *line_north;
	char *line_south;
	char *line_east;
	char *line_west;
	char *line_floor;
	char *line_ceil;

	char    *path_north_texture;
	char    *path_south_texture;
	char    *path_east_texture;
	char    *path_west_texture;
	uint32_t floor_color;
	uint32_t ceil_color;

	bool is_valid;

} t_config;

struct __attribute__((aligned(8))) s_cub3d
{
	t_smlx_instance *smlx;
	t_list          *texture_list;
	t_config         config;
	t_ray            ray;
	t_map            map;
	t_player         player;
};

#endif
