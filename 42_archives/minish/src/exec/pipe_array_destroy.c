/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_array_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:09:35 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/08 11:09:36 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int32_t **pipe_array_destroy(int32_t **pipe_array, const uint64_t pipe_count)
{
    uint64_t i;

    if (!pipe_array)
        return (NULL);
    i = 0;
    while (i < pipe_count)
        memory_dealloc(pipe_array[i++]);
    memory_dealloc(pipe_array);
    return (NULL);
}

