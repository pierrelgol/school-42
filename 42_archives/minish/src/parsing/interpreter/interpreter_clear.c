/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter_clear.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:21:46 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/09 13:21:47 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool interpreter_clear(t_interpreter *const self)
{
	if (!self || !self->is_dirty)
		return (false);
	self->is_dirty = false;
	return (true);
}
