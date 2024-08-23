/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_execute_last_cmd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:10:43 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/08 11:10:44 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void exec_execute_last_cmd(t_exec *const self)
{
	close(self->pipe_array[self->table->id - 1][1]);
	dup2(self->pipe_array[self->table->id - 1][0], STDIN_FILENO);
	close(self->pipe_array[self->table->id - 1][0]);
	exec_execute(self);
}
