#include "../lib/dic_base.h"
#include "../lib/dic_file.h"

t_file	*file_init(const char *path, int flag)
{
	t_file *self;

	if (!path)
		return (NULL);
	self = (t_file*) malloc(sizeof(t_file) * 1);
	if (!self)
		return (NULL);
	*self = (t_file){.fd = 0, .open = false, .size = 0, .buf = NULL};
	self->buf = (char *) malloc(sizeof(char) * BUFFER_SIZE);
	if (!self->buf)
		return (file_dispose(self));
	if (!file_open(self, path, flag))
		return (file_dispose(self));
	if (!file_read(self))
		return (file_dispose(self));
	return (self);
}

bool	file_open(t_file *self, const char *path, int flag)
{
	if (!self)
		return (false);
	self->fd = open(path, flag);
	if (self->fd == -1)
		return (false);
	self->open = true;
	return (true);
}

bool	file_read(t_file *self)
{
	if (!self)
		return (false);
	if (self->fd == -1)
		return (false);
	self->size = read(self->fd, self->buf, BUFFER_SIZE);
	if (self->size == -1)
		return (true);
	return (true);
}

void *file_dispose(t_file *self)
{
	if (!self)
		return (NULL);
	if (self->buf)
		free(self->buf);
	free(self);
	return (NULL);
}
