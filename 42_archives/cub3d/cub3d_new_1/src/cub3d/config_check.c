/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_config_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:45:12 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/24 18:45:12 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool line_is_valid_identifier(t_config *const self, int32_t index, char *const line)
{
	int32_t  split_size;
	t_bitset bitset;
	bool     cond;

	bitset = bitset_init_from_str(" ,0123456789\tFC");
	cond = string_is_all_any(line, &bitset);
	split_size = string_compute_predicate_split_size(line, is_whitespace);
	if (!self->line_north && string_starts_with_sequence(line, "NO ") && split_size == 2)
		self->line_north = self->file_lines[index];
	else if (!self->line_south && string_starts_with_sequence(line, "SO ") && split_size == 2)
		self->line_south = self->file_lines[index];
	else if (!self->line_west && string_starts_with_sequence(line, "WE ") && split_size == 2)
		self->line_west = self->file_lines[index];
	else if (!self->line_east && string_starts_with_sequence(line, "EA ") && split_size == 2)
		self->line_east = self->file_lines[index];
	else if (!self->line_floor && string_starts_with_sequence(line, "F ") && (split_size >= 2 && split_size <= 4) && cond)
		self->line_floor = self->file_lines[index];
	else if (!self->line_ceil && string_starts_with_sequence(line, "C ") && (split_size >= 2 && split_size <= 4) && cond)
		self->line_ceil = self->file_lines[index];
	else
		return (false);
	return (true);
}

bool line_is_valid_description(t_config *const self, char *const line)
{
	t_bitset bitset;
	int32_t  len;

	if (!line)
		return (false);
	bitset = bitset_init_from_str("01NSWE \t");
	len = string_length(line);
	if (len > self->width)
		self->width = len;
	if (string_is_all_any(line, &bitset))
		return (true);
	return (false);
}

bool config_check(t_config *const self)
{
	int32_t identifier_count;
	char   *line;
	int32_t i;

	i = 0;
	identifier_count = 0;
	while (self->file_lines[i])
	{
		line = self->file_lines[i];
		if (line_is_valid_identifier(self, i, line))
			++identifier_count;
		else if (identifier_count == 6 && line_is_valid_description(self, line))
			self->height += 1;
		else
			return (false);
		++i;
	}
	return (true);
}
