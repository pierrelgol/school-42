/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_is_middle_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:14:15 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/08 11:14:15 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	exec_is_middle_cmd(t_exec *const self)
{
	return (!exec_is_first_cmd(self) && !exec_is_last_cmd(self));
}

