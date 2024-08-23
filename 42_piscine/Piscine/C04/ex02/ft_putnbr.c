/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 21:25:27 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/08 21:25:31 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

static void	ft_write_nbr_r(long n)
{
	if (n == 0)
		return ;
	ft_write_nbr_r((n / 10));
	write(1, &"0123456789"[n % 10], 1);
}

void	ft_putnbr(int nb)
{
	long	n;

	n = nb;
	if (n <= 0)
	{
		if (n == 0)
			write(1, &"0", 1);
		else
		{
			write(1, &"-", 1);
			n *= -1;
		}
	}
	ft_write_nbr_r(n);
}
// #include <limits.h>
// int main(void)
// {
// 	ft_putnbr(INT_MAX);
// 	write(1, "\n", 2);
// 	ft_putnbr(0);
// 	write(1, "\n", 2);
// 	ft_putnbr(INT_MIN);		
// 	write(1, "\n", 2);
// 	return (0);
// }