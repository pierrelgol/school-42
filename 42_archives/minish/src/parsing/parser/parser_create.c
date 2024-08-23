/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:31:20 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/04 16:31:20 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_parser	*parser_create(t_list *const token_pool)
{
	t_parser	*self;

	self = (t_parser *)memory_alloc(sizeof(t_parser));
	if (!self)
		return (NULL);
	self->token_pool = token_pool;
	self->expr_list = list_create();
	self->is_dirty = false;
	return (self);
}
