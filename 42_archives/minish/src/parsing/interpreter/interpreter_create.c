/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter_create.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:21:28 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/09 13:21:28 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_interpreter *interpreter_create(t_list *expression_list)
{
	t_interpreter *self;

	self = (t_interpreter*) memory_alloc(sizeof(t_interpreter));
	if (!self)
		return (NULL);
	self->expression_list = expression_list;
	self->interpreted_list = list_create();
	self->is_dirty = false;
	self->it = NULL;
	return (self);
}

