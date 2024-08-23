/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_open_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:32:59 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/08 11:33:00 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void exec_open_pipe(t_exec *const self)
{
	if (!self->pipe_count || !self->pipe_array)
		return;
	pipe(self->pipe_array[self->table->id]);
}
