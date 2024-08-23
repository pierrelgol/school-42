#ifndef DIC_FILE_H
#define DIC_FILE_H

#include "dic_base.h"

t_file	*file_init(const char *path, int flag);
bool	file_open(t_file *self, const char *path, int flag);
bool	file_read(t_file *self);
void	*file_dispose(t_file *self);

#endif
