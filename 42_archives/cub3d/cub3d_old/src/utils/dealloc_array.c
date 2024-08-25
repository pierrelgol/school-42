/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealloc_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:31:17 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/23 16:31:17 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	dealloc_array(char **array)
{
	int32_t	i;

	i = 0;
	if (!array)
		return;
	i = 0;
	while (array[i])
		dealloc(array[i++]);
	dealloc(array);
}
