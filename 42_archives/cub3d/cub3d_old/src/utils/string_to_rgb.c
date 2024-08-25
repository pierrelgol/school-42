/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_to_rgb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:10:10 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/23 18:10:11 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int32_t	string_to_rgb(const char *const line)
{
	int32_t number;
	int32_t i;

	if (!line || line[0] == '-' || line[0] == '+')
		return (-1);
	i = 0;
	number = 0;
	while (line[i] && is_digit(line[i]))
		number = (line[i++] - '0') + number * 10;
	if (number > 255)
		return (-1);
	return (number);
}
