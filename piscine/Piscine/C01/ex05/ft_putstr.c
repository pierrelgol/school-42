/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:30:27 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/07 13:30:30 by pollivie         ###   ########.fr       */
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
