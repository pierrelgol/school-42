/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bissenma <bissenma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:53:51 by bissenma          #+#    #+#             */
/*   Updated: 2023/09/24 15:54:26 by bissenma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/num_base.h"
#include "../lib/num_file.h"

t_file	*file_init(char *buffer)
{
	t_file	*self;

	if (!buffer)
		return (NULL);
	self = (t_file *)malloc(sizeof(t_file) * 1);
	if (!self)
		return (NULL);
	*self = (t_file){0, 0, .status = DEFAULTV, 0, .buffer = buffer};
	return (self);
}

bool	file_open(t_file *self, const char *path, int right_flag)
{
	if (!self)
		return (false);
	self->fd = open(path, right_flag);
	if (self->fd == -1)
	{
		self->status = ERR_FNAM;
		return (false);
	}
	return (true);
}

bool	file_read(t_file *self)
{
	if (!self)
		return (false);
	if (self->fd == -1 || self->status != DEFAULTV)
		return (false);
	self->byte_read = read(self->fd, self->buffer, BUFFER_SIZE);
	if (self->byte_read == -1)
	{
		self->status = ERR_PERM;
		return (false);
	}
	return (true);
}

bool	file_dump(t_file *self)
{
	if (!self)
		return (false);
	if (self->status != DEFAULTV)
		return (false);
	write(self->fd, self->buffer, self->byte_read);
	return (true);
}

bool	file_dispose(t_file *self)
{
	if (!self)
		return (false);
	if (self->buffer)
		free(self->buffer);
	free(self);
	return (false);
}
