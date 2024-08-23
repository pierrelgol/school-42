/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreted_create.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:29:21 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/09 13:29:21 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

t_interpreted *interpreted_create(t_interpreted_kind kind)
{
	t_interpreted *self;

	self = (t_interpreted *) memory_alloc(sizeof(t_interpreted));
	if (!self)
		return (NULL);
	self->expr_list = NULL;
	self->cmd_table = NULL;
	self->kind = kind;
	self->maybe_file = NULL;
	return (self);
}
