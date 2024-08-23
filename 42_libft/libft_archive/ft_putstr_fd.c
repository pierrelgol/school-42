/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierreollivier <plgol.perso@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:24:14 by pierreollivie     #+#    #+#             */
/*   Updated: 2023/07/07 17:24:17 by pierreollivie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	char	*ps;
	size_t	byte_count;

	ps = s;
	byte_count = 0;
	while (*ps)
	{
		ps++;
		byte_count++;
	}
	write(fd, s, byte_count);
}
