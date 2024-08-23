/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_is_the_only_cmd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:13:48 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/08 11:13:49 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool exec_is_the_only_cmd(t_exec *const self)
{
	return (!self->pipe_count && self->ctl->size == 1);
}
