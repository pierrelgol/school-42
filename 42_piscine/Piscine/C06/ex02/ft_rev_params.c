/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:39:05 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/12 12:39:08 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	main(int argc, char *argv[])
{
	unsigned int	arglen;

	while (argc > 1)
	{
		arglen = 0;
		while (argv[argc - 1][arglen])
			++arglen;
		write(1, argv[argc - 1], arglen);
		write(1, &"\n", 1);
		--argc;
	}
	return (0);
}
