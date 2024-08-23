/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_close_pipe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:33:21 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/08 11:33:22 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void exec_close_pipe(t_exec *const self)
{
	if (!self->pipe_count || !self->pipe_array)
		return;
	close(self->pipe_array[self->table->id - 1][0]);
	close(self->pipe_array[self->table->id - 1][1]);
}
