/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:06:49 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/08 11:06:50 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void print_array(char **array)
{
	printf("\n");
	for (uint64_t i = 0; array[i]; ++i)
		printf("[%lu]%s\n", i, array[i]);
	fflush(stdout);
}


void exec_init(t_exec *self, t_list *expression_list, char **envp)
{
	self->ctl = expression_list;
	self->pid = 0;
	self->envp = envp;
	self->table = NULL;
	self->pipe_count = list_size(expression_list) - 1;
	self->pipe_array = pipe_array_create(self->pipe_count);
	self->is_dirty = false;
}
