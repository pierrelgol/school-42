/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:29:15 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/23 16:29:16 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int32_t file_size(const char *const filename)
{
	char    read_buffer[4096];
	int32_t bread;
	int32_t size;
	int32_t fd;

	if (!filename)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	bread = 4096;
	size = 0;
	while (bread == 4096)
	{
		bread = read(fd, read_buffer, 4096);
		size += bread;
	}
	close(fd);
	return (size);
}

static char *open_read_to_end_alloc(const char *const filename)
{
	char   *result;
	int32_t size;
	int32_t fd;

	if (!filename)
		return (NULL);
	size = file_size(filename);
	if (size == -1)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	result = (char *) alloc(size + 1);
	if (!result)
		return (NULL);
	read(fd, result, size);
	close(fd);
	result[size] = 0;
	return (result);
}

bool config_init(t_config *const self, const char *const filename)
{
	if (!self || !filename)
		return (false);
	self->file_buffer = open_read_to_end_alloc(filename);
	if (!self->file_buffer)
		return (false);
	self->file_lines = string_split_scalar(self->file_buffer, '\n');
	if (!config_check(self))
		return (false);
	if (!config_parse(self))
		return (false);
	return (true);
}

void config_deinit(t_config *const self)
{
	if (!self)
		return;
	if (self->file_buffer)
		dealloc(self->file_buffer);
	if (self->file_lines)
		dealloc_array(self->file_lines);
	if (self->path_north_texture)
		dealloc(self->path_north_texture);
	if (self->path_south_texture)
		dealloc(self->path_south_texture);
	if (self->path_east_texture)
		dealloc(self->path_east_texture);
	if (self->path_west_texture)
		dealloc(self->path_west_texture);
	zeroed(self, sizeof(*self));
}
