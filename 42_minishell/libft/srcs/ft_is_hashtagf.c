/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_hashtagf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:37:56 by bifernan          #+#    #+#             */
/*   Updated: 2024/01/02 14:38:04 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_is_hashtagf(const char *flags)
{
	while (*flags != '\0')
	{
		if (*flags == '#')
			return (1);
		flags++;
	}
	return (0);
}
