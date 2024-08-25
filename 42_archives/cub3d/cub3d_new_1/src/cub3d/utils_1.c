/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:44:49 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/24 18:45:26 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void dealloc_array(char **array)
{
	int32_t i;

	i = 0;
	if (!array)
		return;
	i = 0;
	while (array[i])
		dealloc(array[i++]);
	dealloc(array);
}

int32_t string_to_rgb(const char *const line)
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

void	print_fps(int64_t delta_time)
{
	double fps = 1000.0 / (delta_time);

	printf("fps : %.2f\n",fps);
}
