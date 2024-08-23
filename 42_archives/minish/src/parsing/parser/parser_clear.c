/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:50:45 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/05 09:50:45 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	parser_clear(t_parser *const self)
{
	if (!self || !self->is_dirty)
		return (false);
	list_clear(self->expr_list, expression_dtor);
	list_destroy(self->expr_list);
	self->expr_list = list_create();
	self->is_dirty = false;
	return (true);
}
