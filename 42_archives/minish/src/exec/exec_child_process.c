/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_child_process.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:15:52 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/08 11:15:53 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_child_process(t_exec *const self)
{
	if (exec_is_the_only_cmd(self))
		exec_execute(self);
	if (exec_is_first_cmd(self) && !exec_is_the_only_cmd(self))
		exec_execute_first_cmd(self);
	if (exec_is_middle_cmd(self))
		exec_execute_middle_cmd(self);
	if (exec_is_last_cmd(self) && !exec_is_the_only_cmd(self))
		exec_execute_last_cmd(self);
}
