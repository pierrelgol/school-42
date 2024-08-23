/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:10:10 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/08 11:10:10 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void exec_deinit(t_exec *const self)
{
	if (!self)
		return;
	self->pipe_array = pipe_array_destroy(self->pipe_array, self->pipe_count);
}
