/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_parent_process.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:15:44 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/08 11:15:44 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void exec_parent_process(t_list *const ctl, char **envp)
{
	t_list_iter *it;
	t_exec       exec;

	if (!ctl || !envp)
		return;
	exec_init(&exec, ctl, envp);
	it = list_iter_create(ctl);
	while (!it_end(it))
	{
		exec.table = it_peek_curr(it);
		if (!exec_is_last_cmd(&exec) && !exec_is_the_only_cmd(&exec))
		{
			printf("HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHI");
			exec_open_pipe(&exec);
		}
		if (!exec_is_builtin_cmd(&exec))
			exec_launch_child_process(&exec);
		if (!exec_is_first_cmd(&exec))
			exec_close_pipe(&exec);

		it_advance(it);
	}
	it = list_iter_destroy(it);
	exec_deinit(&exec);
}
