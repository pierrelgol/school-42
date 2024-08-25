/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:31:26 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/23 17:31:26 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool config_fill_texture_path(char **out_path, char *const line)
{
	char **temp;

	*out_path = NULL;
	temp = string_split_scalar(line, ' ');
	if (!temp)
		return (false);
	*out_path = string_clone(temp[1]);
	dealloc_array(temp);
	return (true);
}

bool config_fill_colors(uint32_t *out_color, char *const line)
{
	t_bitset bitset;
	char **temp;
	int32_t r;
	int32_t g;
	int32_t b;

	*out_color = SMLX_SOLID_WHITE;
	bitset = bitset_init_from_str(", \t\v\r");
	temp = string_split_any(line, &bitset);
	if (!temp)
		return (false);
	if (string_split_size(temp) != 4)
		return (dealloc_array(temp), (false));
	r = string_to_rgb(temp[1]);
	g = string_to_rgb(temp[2]);
	b = string_to_rgb(temp[3]);
	if (r == -1 || g == -1 || b == -1)
		return (dealloc_array(temp), (false));
	*out_color = (r << 16) + (g << 8) + (b);
	return (dealloc_array(temp), (true));
}

bool	config_parse(t_config *const self)
{
	if (!config_fill_texture_path(&self->path_north_texture, self->line_north))
		return (false);
	if (!config_fill_texture_path(&self->path_south_texture, self->line_south))
		return (false);
	if (!config_fill_texture_path(&self->path_east_texture, self->line_east))
		return (false);
	if (!config_fill_texture_path(&self->path_west_texture, self->line_west))
		return (false);
	if (!config_fill_colors(&self->floor_color, self->line_floor))
		return (false);
	if (!config_fill_colors(&self->ceil_color, self->line_ceil))
		return (false);
	self->is_valid = true;
	return (true);
}

