/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isflag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:38:52 by bifernan          #+#    #+#             */
/*   Updated: 2024/01/02 14:38:57 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_isflag(char c, const char *flags)
{
	while (*flags != '\0')
	{
		if (c == *flags)
			return ((int)c);
		flags++;
	}
	return (0);
}
