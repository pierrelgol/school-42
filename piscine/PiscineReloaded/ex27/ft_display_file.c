/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:45:48 by pollivie          #+#    #+#             */
/*   Updated: 2023/10/30 16:45:49 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

#define ERR_FMISS 1
#define ERR_MARGS 2
#define ERR_RFILE 3

#define BUFFER_SIZE 16384

void	ft_putstr(char *str)
{
	int	slen;

	if (*str)
	{
		slen = 0;
		while (str[slen])
			++slen;
		write(1, str, slen);
	}
}

void	ft_error_handler(int error_code)
{
	if (error_code == ERR_FMISS)
		ft_putstr("File name missing.\n");
	if (error_code == ERR_MARGS)
		ft_putstr("Too many arguments.\n");
	if (error_code == ERR_RFILE)
		ft_putstr("Cannot read file.\n");
}

void	ft_print_file(char *path, char *buffer)
{
	int	fd;
	int	size;

	if (!path)
		return ;
	fd = open(path, O_RDONLY);
	if (fd != -1)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size != -1)
			write(1, buffer, size);
		else
			ft_error_handler(ERR_RFILE);
	}
	else
		ft_error_handler(ERR_RFILE);
}

int	main(int argc, char **argv)
{
	char	*buffer;

	buffer = (char [BUFFER_SIZE]){0};
	if (argc == 2)
		ft_print_file(argv[1], buffer);
	else if (argc > 2)
		ft_error_handler(ERR_MARGS);
	else
		ft_error_handler(ERR_FMISS);
	return (0);
}
