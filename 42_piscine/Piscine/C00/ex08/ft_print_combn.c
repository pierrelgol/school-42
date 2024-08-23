/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:34:33 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/06 11:34:41 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

static void	ft_print_number(int *num, int depth)
{
	int		i;
	char	ch;

	i = 0;
	while (i < depth)
	{
		ch = num[i++] + '0';
		write(1, &ch, 1);
	}
	if (num[0] != 10 - depth)
		write(1, ", ", 2);
}

static void	ft_compute_combn(int *num, int final_depth, int depth, int prev_i)
{
	int	i;

	if (depth == final_depth)
	{
		ft_print_number(num, final_depth);
		return ;
	}
	i = prev_i + 1;
	while (i < 10)
	{
		num[depth] = i;
		ft_compute_combn(num, final_depth, depth + 1, i);
		i++;
	}
}

void	ft_print_combn(int n)
{
	if (n >= 1 && n <= 9)
		ft_compute_combn((int [9]){0}, n, 0, -1);
}
