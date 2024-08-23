/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:59:43 by pollivie          #+#    #+#             */
/*   Updated: 2023/10/02 11:59:44 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_recursive(long numb, int fd)
{
	if (numb == 0)
		return ;
	ft_putnbr_recursive(numb / 10, fd);
	write(fd, &"0123456789"[numb % 10], 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	numb;

	if (fd < 0)
		return ;
	numb = n;
	if (numb == 0)
		write(fd, "0", 1);
	if (numb < 0)
	{
		numb *= -1;
		write(fd, "-", 1);
	}
	ft_putnbr_recursive(numb, fd);
}
