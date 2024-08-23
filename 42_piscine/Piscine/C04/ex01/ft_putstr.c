/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 21:24:50 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/08 21:25:03 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putstr(char *str)
{
	int	slen;

	if (str != (void *)0)
	{
		slen = 0;
		while (str[slen])
			++slen;
		write(1, str, slen);
	}
}
// int main(int ac, char *av[])
// {
// 	if(ac == 2)
// 		ft_putstr(av[1]);
// 	return (0);
// }