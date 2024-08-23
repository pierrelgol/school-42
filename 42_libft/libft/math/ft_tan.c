/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tan.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:45:57 by pollivie          #+#    #+#             */
/*   Updated: 2023/10/17 13:45:59 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

float	ft_tan(float x)
{
	float	sin_x;
	float	cos_x;

	sin_x = ft_sin(x);
	cos_x = ft_cos(x);
	if (cos_x == 0)
		return (-1);
	return (sin_x / cos_x);
}
