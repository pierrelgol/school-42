/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:46:37 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/12 12:46:53 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

static unsigned int	ft_sum(char *arg)
{
	unsigned int	sum;

	sum = 0;
	while (*arg)
		sum += (unsigned char)*arg++;
	return (sum);
}

static void	ft_sort_params(int argc, char *argv[])
{
	char	*temp;
	int		i;

	if (argc >= 3)
	{
		i = 2;
		while (i < argc)
		{
			while (i >= 2 && ft_sum(argv[i - 1]) > ft_sum(argv[i]))
			{
				temp = argv[i - 1];
				argv[i - 1] = argv[i];
				argv[i] = temp;
				--i;
			}
			++i;
		}
	}
}

int	main(int argc, char *argv[])
{
	unsigned int	arglen;
	int				i;

	i = 1;
	ft_sort_params(argc, argv);
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
