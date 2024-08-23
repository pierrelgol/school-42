#ifndef DIC_HELP_H
#define DIC_HELP_H

#include "dic_base.h"

int	help_strlen(char *str);
int help_atoi(char *nbr);
int help_isalpha(char ch);
int help_isalnum(char ch);
int help_isnum(char ch);
int help_issep(char ch);
int help_isprintable(char ch);
int help_isspace(char ch);
int help_strdup(char **dst, char *src);
int	help_strncpy(char *dst, char *src, int n);

#endif
