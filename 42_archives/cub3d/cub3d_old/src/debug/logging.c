/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logging.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:46:42 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/23 14:46:43 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void log_info(const char *const msg)
{
	printf("[INFO]: %s\n", msg);
}

void log_assert(bool cond, const char *const msg)
{
	if (!cond)
		printf("assertiong failed : %s\n", msg);
}

void log_cub3d(t_cub3d *const self, const char *const label)
{
	printf("---------------- %s -------------------\n", label);
	printf("                                       \n");
	printf("struct s_cub3d                  '%p'   \n", self);
	printf("{                                      \n");
	printf("    t_smlx_instance *smlx;      '%p'   \n", self->smlx);
	printf("                                       \n");
	printf("    struct s_config                    \n");
	printf("    {                                  \n");
	printf("        int32_t  map_start;   '%d'     \n", self->config.map_start);
	printf("        int32_t  width;       '%d'     \n", self->config.width);
	printf("        int32_t  height;      '%d'     \n", self->config.height);
	printf("        char     *file_buffer;'%p'     \n", self->config.file_buffer);
	printf("        char     *file_lines; '%p'     \n", self->config.file_lines);
	printf("                                       \n");
	printf("        char     *no_texture; '%p'     \n", self->config.path_north_texture);
	printf("        char     *so_texture; '%p'     \n", self->config.path_south_texture);
	printf("        char     *ea_texture; '%p'     \n", self->config.path_east_texture);
	printf("        char     *we_texture; '%p'     \n", self->config.path_west_texture);

	printf("        char     *no_texture; '%s'     \n", self->config.line_north);
	printf("        char     *so_texture; '%s'     \n", self->config.line_south);
	printf("        char     *ea_texture; '%s'     \n", self->config.line_east);
	printf("        char     *we_texture; '%s'     \n", self->config.line_west);
	printf("        char     *floor_line; '%s'     \n", self->config.line_floor);
	printf("        char     *ceil_line;  '%s'     \n", self->config.line_ceil);
	printf("                                       \n");
	printf("        uint32_t floor_color; '%X'     \n", self->config.floor_color);
	printf("        uint32_t ceil_color;  '%X'     \n", self->config.ceil_color);
	printf("                                       \n");
	printf("        bool     is_valid;    '%d'     \n", self->config.is_valid);
	printf("    };                                 \n");
	printf("                                       \n");
	printf("    struct s_ray                       \n");
	printf("    {                                  \n");
	printf("        t_vec2   pos.x;       '%.2f'   \n", self->ray.pos.x);
	printf("        t_vec2   pos.y;       '%.2f'   \n", self->ray.pos.y);
	printf("        t_vec2   dir.x;       '%.2f'   \n", self->ray.dir.x);
	printf("        t_vec2   dir.y;       '%.2f'   \n", self->ray.dir.y);
	printf("        t_vec2   dstside.x;   '%.2f'   \n", self->ray.dist_side.x);
	printf("        t_vec2   dstside.y;   '%.2f'   \n", self->ray.dist_side.y);
	printf("        t_vec2   dstdelt.x;   '%.2f'   \n", self->ray.dist_delt.x);
	printf("        t_vec2   dstdelt.y;   '%.2f'   \n", self->ray.dist_delt.y);
	printf("        double_t dist_perp;   '%.2f'   \n", self->ray.dist_perp);
	printf("        int32_t  step_x;      '%d'     \n", self->ray.step_x);
	printf("        int32_t  step_y;      '%d'     \n", self->ray.step_y);
	printf("        int32_t  map_x;       '%d'     \n", self->ray.map_x);
	printf("        int32_t  map_y;       '%d'     \n", self->ray.map_y);
	printf("        int32_t  hit;         '%d'     \n", self->ray.hit);
	printf("        int32_t  side;        '%d'     \n", self->ray.side);
	printf("    };                                 \n");
	printf("                                       \n");
	printf("    struct s_player                    \n");
	printf("    {                                  \n");
	printf("        t_vec2  pos.x;        '%.2f'   \n",self->player.pos.x);
	printf("        t_vec2  pos.y;        '%.2f'   \n",self->player.pos.y);
	printf("        t_vec2  dir.x;        '%.2f'   \n",self->player.dir.x);
	printf("        t_vec2  dir.y;        '%.2f'   \n",self->player.dir.x);
	printf("        t_vec2  plane.x;      '%.2f'   \n",self->player.plane.x);
	printf("        t_vec2  plane.y;      '%.2f'   \n",self->player.plane.x);
	printf("        float_t mov_step;     '%.2f'   \n",self->player.mov_step);
	printf("        float_t rot_step;     '%.2f'   \n",self->player.rot_step);
	printf("    };                                 \n");
	printf("                                       \n");
	printf("    struct s_map                       \n");
	printf("    {                                  \n");
	printf("        char     **map;       '%p'     \n", self->map.map);
	printf("        int32_t  width;       '%d'     \n", self->map.width);
	printf("        int32_t  height;      '%d'     \n", self->map.height);
	printf("    };                                 \n");
	printf("}                                      \n");
}

void	log_map(t_map *const self)
{
	int32_t	i;

	printf("MAP\n");
	printf("height = %d\n", self->height);
	printf("width  = %d\n",self->width);
	if (self->map)
	{
		i = 0;
		while (i < self->height)
			printf("%s\n",self->map[i++]);
		
	}
	printf("\n");

}
