/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_has_input_redirect.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:11:40 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/08 11:11:41 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	exec_cmd_has_input_redirect(t_exec *const self)
{
	return (self->table->fd_array[0] != -1);
}
