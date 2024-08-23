/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 03:39:31 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/23 03:39:32 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libgen.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

#define BUFFER_SIZE 16384


void	ft_error_handler(int error_code, char *name)
{
	ft_putstr(": ");
	if (name)
	{
		ft_putstr(name);
		write(1, ": ", 2);
		ft_putstr(strerror(error_code));
		write(1, "\n", 1);
	}

}

void	ft_print_file(char *path, char *buffer)
{
	int	fd;
	int	size;

	fd = 0;
	size = 0;
	if (!path || !buffer)
		ft_error_handler(errno, basename(path));

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_error_handler(errno, basename(path));
		return ;
	}
	size = read(fd, buffer, BUFFER_SIZE);
	write(1, buffer, size);
}



int	main(int argc, char **argv)
{
	char	*buffer;
	int		index;

	buffer = (char [BUFFER_SIZE]){0};
	index = 1;
	if (argc == 2)
		ft_print_file(argv[1], buffer);
	else if (argc > 2)
	{
		while (index < argc)
			ft_print_file(argv[index++], buffer);
	}
	else
		ft_error_handler(errno, NULL);
	return (0);
}
