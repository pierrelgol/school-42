/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_execute_middle_cmd.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:10:37 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/08 11:10:37 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void exec_execute_middle_cmd(t_exec *const self)
{
	close(self->pipe_array[self->table->id - 1][1]);
	close(self->pipe_array[self->table->id][0]);
	dup2(self->pipe_array[self->table->id - 1][0], STDIN_FILENO);
	dup2(self->pipe_array[self->table->id][1], STDOUT_FILENO);
	close(self->pipe_array[self->table->id - 1][0]);
	close(self->pipe_array[self->table->id][1]);
	exec_execute(self);
}
