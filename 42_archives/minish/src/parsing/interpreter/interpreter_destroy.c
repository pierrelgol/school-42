/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter_destroy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:21:35 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/09 13:21:36 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_interpreter *interpreter_destroy(t_interpreter *const self)
{
	if (!self)
		return (NULL);
	if (self->is_dirty)
		interpreter_clear(self);
	list_destroy(self->interpreted_list);
	memory_dealloc(self);
	return (NULL);
}
