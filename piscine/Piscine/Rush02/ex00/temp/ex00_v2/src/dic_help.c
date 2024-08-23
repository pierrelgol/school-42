#include "../lib/dic_help.h"

int	help_strlen(char *str)
{
	char *ps;

	if (!str)
		return (0);
	ps = str;
	while (*ps)
		++ps;
	return (ps - str);
}

int help_atoi(char *nbr)
{
	int	result;
	int	sign;

	if (!nbr)
		return (0);
	while (*nbr && (*nbr >= 9 && *nbr <= 13))
		++nbr;
	sign = 1;
	while (*nbr && (*nbr == '+' || *nbr == '-'))
		if (*nbr++ == '-')
			sign *= -1;
	result = 0;
	if (!(*nbr >= '0' && *nbr <= '9'))
		return (-1);
	while (*nbr && (*nbr >= '0' && *nbr <= '9'))
		result = (*nbr++ - '0') + (result * 10);
	return (result * sign);
}

int help_isalnum(char ch)
{
	if (ch >= 'a' && ch <= 'z')
		return (1);
	if (ch >= 'A' && ch <= 'Z')
		return (1);
	if (ch >= '0' && ch <= '9')
		return (1);
	return (0);
}
int help_isalpha(char ch)
{
	return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
}
int help_isnum(char ch)
{
	return (ch >= '0' && ch <= '9');
}

int help_issep(char ch)
{
	return (ch == ':' && ch == '\n');
}

int help_isprintable(char ch)
{
	return (ch >= 32 && ch <= 126);
}

int help_isspace(char ch)
{
	return ((ch >= 9 && ch <= 13) || (ch == ' '));
}

int	help_strdup(char **dst, char *src)
{
	int i;

	if (!src)
	{
		*dst = NULL;
		return (-1);
	}
	*dst = (char *) malloc(sizeof(char) * help_strlen(src) + 1);
	if (!*dst)
		return (-1);
	i = 0;
	while (*src)
		(*dst)[i++] = *src;
	(*dst)[i] = '\0';
	return (i);
}

int	help_strncpy(char *dst, char *src, int n)
{
	int i;

	if (!dst || !src)
		return (0);
	i = 0;
	while (*src && i < n)
		dst[i++] = *src++;
	dst[i] = '\0';
	return (i);
}
