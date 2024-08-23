/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:33:48 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/12 12:34:06 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	main(int argc, char **argv)
{
	unsigned int	arglen;
	int				i;

	i = 1;
	while (i < argc)
	{
		arglen = 0;
		while (argv[i][arglen])
			++arglen;
		write(1, argv[i], arglen);
		write(1, &"\n", 1);
		++i;
	}
	return (0);
}
