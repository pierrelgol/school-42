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


#define SMLX_ROSE_PINE_BASE 0x191724
#define SMLX_ROSE_PINE_SURFACE 0x1f1d2e
#define SMLX_ROSE_PINE_OVERLAY 0x26233a
#define SMLX_ROSE_PINE_MUTED 0x6e6a86
#define SMLX_ROSE_PINE_SUBTLE 0x908caa
#define SMLX_ROSE_PINE_WHITE 0xe0def4
#define SMLX_ROSE_PINE_RED 0xeb6f92
#define SMLX_ROSE_PINE_YELLOW 0xf6c177
#define SMLX_ROSE_PINE_ROSE 0xebbcba
#define SMLX_ROSE_PINE_PINE 0x31748f
#define SMLX_ROSE_PINE_FOAM 0x9ccfd8
#define SMLX_ROSE_PINE_IRIS 0xc4a7e7
#define SMLX_ROSE_PINE_HLLOW 0x21202e
#define SMLX_ROSE_PINE_HLMED 0x403d52
#define SMLX_ROSE_PINE_HLHIG 0x524f67

#define SMLX_SOLID_WHITE   0xFFFFFF
#define SMLX_SOLID_GRAY    0xCCCCCC
#define SMLX_SOLID_BLACK   0x000000
#define SMLX_SOLID_RED     0xFF0000
#define SMLX_SOLID_GREEN   0x00FF00
#define SMLX_SOLID_BLUE    0x0000FF
#define SMLX_SOLID_YELLOW  0xFFFF00
#define SMLX_SOLID_CYAN    0x00FFFF
#define SMLX_SOLID_MAGENTA 0xFF00FF
#define SMLX_SOLID_ORANGE  0xFF9900
#define SMLX_SOLID_PURPLE  0x9900FF
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

struct s_node
{
	struct s_node *next;
	struct s_node *prev;
	uintptr_t      data;
};

struct s_list
{
	t_node  *head;
	t_node  *tail;
	uint64_t size;
};

struct s_entry
{
	char     *key;
	uintptr_t value;
};

struct s_hashmap
{
	uint64_t size;
	uint64_t capacity;
	t_entry *body;
};

struct s_smlx_texture
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

struct s_smlx_bresenham
{
	int32_t dx;
	int32_t dy;
	int32_t sx;
	int32_t sy;
	int32_t err;
	int32_t e2;
};

typedef struct s_vec2i
{
	int32_t x;
	int32_t y;
} t_vec2i;

struct s_smlx_frame_buffer
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

struct s_smlx_instance
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

struct s_vec2
{
	float x;
	float y;
};

typedef struct s_map
{
	int32_t width;
	int32_t height;
	char  **map;
} t_map;

typedef struct s_player
{
	t_map  *map;
	t_vec2  bound_min;
	t_vec2  bound_max;
	t_vec2  pos;
	t_vec2  dir;
	t_vec2  plane;
	int64_t	time_last_move;
	int32_t	move_x;
	int32_t	move_y;
	int32_t	rota_x;
	int32_t	rota_y;
	float_t	amount;

} t_player;

typedef struct s_ray
{
	t_map    *map;
	t_player *player;
	double_t  camera_x;
	double_t  dist_perp;
	int32_t   hit;
	int32_t   line_height;
	int32_t   map_x;
	int32_t   map_y;
	int32_t   side;
	int32_t   step_x;
	int32_t   step_y;
	int32_t	  height;
	uint32_t  color;
	uint32_t  orientation;
	float_t	 wall_x;
	t_vec2    dir;
	t_vec2    dist_delt;
	t_vec2    dist_side;
	t_vec2i   draw_range;
	t_vec2    pos;
} t_ray;

typedef struct s_config
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

struct s_cub3d
{
	int32_t	height;
	int32_t width;
	t_smlx_instance *smlx;
	t_config        *config;
	t_ray           *ray;
	t_map           *map;
	t_player        *player;
	t_smlx_texture	*no_texture;
	t_smlx_texture	*so_texture;
	t_smlx_texture	*we_texture;
	t_smlx_texture	*ea_texture;
};

#endif
