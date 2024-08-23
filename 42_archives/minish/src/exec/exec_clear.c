/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:13:02 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/08 11:13:03 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	exec_clear(t_exec *const self)
{
	if (!self || !self->is_dirty)
		return (false);
	self->is_dirty = false;
	return (true);
}
