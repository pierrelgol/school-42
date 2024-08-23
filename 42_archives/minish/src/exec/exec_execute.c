/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_execute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:10:16 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/08 11:10:16 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void exec_execute(t_exec *const self)
{
	if (exec_cmd_has_input_redirect(self))
	{
		dup2(self->table->fd_array[0], STDIN_FILENO);
		close(self->table->fd_array[0]);
	}
	if (exec_cmd_has_output_redirect(self) && self->table->output_type == TRUNC)
	{
		dup2(self->table->fd_array[1], STDOUT_FILENO);
		close(self->table->fd_array[1]);
	}
	if (exec_cmd_has_append_redirect(self) && self->table->output_type == APPEND)
	{
		dup2(self->table->fd_array[2], STDOUT_FILENO);
		close(self->table->fd_array[2]);
	}
	print_array(self->table->cmd_argv);
	execve(self->table->cmd_argv[0], self->table->cmd_argv, self->envp);
}
