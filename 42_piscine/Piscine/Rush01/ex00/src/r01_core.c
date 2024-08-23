/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r01_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:01:56 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/17 20:01:58 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/r01_args.h"
#include "../lib/r01_core.h"
#include "../lib/r01_map.h"

void	print_map(t_map *map)
{
	int		i;
	int		j;
	char	ch;

	i = 0;
	while (i < map->map_dim)
	{
		j = 0;
		while (j < map->map_dim)
		{
			ch = map->map[i][j] + '0';
			write(1, &ch, 1);
			if ((j + 1) != map->map_dim)
				write(1, " ", 1);
			++j;
		}
		write(1, "\n", 1);
		++i;
	}
}

int	main(int argc, char **argv)
{
	t_args	*in;
	t_map	*map;

	if (argc == 2)
	{
		in = args_init(argv[1]);
		map = map_init(in);
		print_map(map);
		map_dispose(map);
		args_dispose(in);
	}
	return (0);
}
