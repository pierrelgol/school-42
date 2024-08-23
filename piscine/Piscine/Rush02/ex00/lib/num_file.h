#ifndef NUM_FILE_H
#define NUM_FILE_H

#include "num_helpers.h"
#include "num_debug.h"

t_file	*file_init(char *buffer);
bool	file_open(t_file *self, const char *path, int right_flag);
bool	file_read(t_file *self);
bool	file_write(t_file *self);
bool	file_dispose(t_file *self);

#endif
