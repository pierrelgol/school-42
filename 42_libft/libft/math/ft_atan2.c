/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atan2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:43:06 by pollivie          #+#    #+#             */
/*   Updated: 2023/10/17 13:43:07 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

float	ft_atan2(float y, float x)
{
	if (x > 0)
		return (ft_atan(y / x));
	else if (y >= 0 > x)
		return (ft_atan(y / x) + PI);
	else if (y < 0 < x)
		return (ft_atan(y / x) - PI);
	else if (y <= 0 < x)
		return (ft_atan(y / x) - PI);
	else
		return (0);
}
