/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_execute_first_cmd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:10:30 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/08 11:10:31 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void exec_execute_first_cmd(t_exec *const self)
{
	close(self->pipe_array[0][0]);
	dup2(self->pipe_array[0][1], STDOUT_FILENO);
	close(self->pipe_array[0][1]);
	exec_execute(self);
}
