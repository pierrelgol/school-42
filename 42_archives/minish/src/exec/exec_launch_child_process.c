/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_launch_child_process.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:16:02 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/08 11:16:02 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void	exec_launch_child_process(t_exec *const self)
{
	self->pid = fork();
	if (self->pid == 0)
		exec_child_process(self);
}
