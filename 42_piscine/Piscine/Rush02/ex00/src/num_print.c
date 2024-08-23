/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bissenma <bissenma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:11:07 by aalric            #+#    #+#             */
/*   Updated: 2023/09/24 15:52:01 by bissenma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/num_print.h"

void	print_putstr(char *str)
{
	if (!str)
		return ;
	write(1, str, helpers_strlen(str));
}

void	print_putnbr(long nbr)
{
	if (nbr <= 0)
	{
		if (nbr == 0)
			write(1, "0", 1);
		else
		{
			write(1, "-", 1);
			nbr *= -1;
		}
	}
	print_putnbr_recurs(nbr);
}

void	print_putnbr_recurs(long nbr)
{
	if (nbr == 0)
		return ;
	print_putnbr_recurs(nbr / 10);
	write(1, &"0123456789"[nbr % 10], 1);
}
