/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_array_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:09:28 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/08 11:09:29 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include "minishell.h"

int32_t **pipe_array_create(const uint64_t pipe_count)
{
	int32_t **pipe_array;
	uint64_t  i;

	pipe_array = (int32_t **) memory_alloc((pipe_count + 1) * sizeof(int32_t *));
	if (!pipe_array)
		return (NULL);
	i = 0;
	while (i < pipe_count)
	{
		pipe_array[i] = memory_alloc(2 * sizeof(int32_t));
		if (!pipe_array[i])
		{
			while (i > 0)
				memory_dealloc(pipe_array[--i]);
			memory_dealloc(pipe_array);
			return (NULL);
		}
		++i;
	}
	pipe_array[pipe_count] = NULL;
	return (pipe_array);
}
