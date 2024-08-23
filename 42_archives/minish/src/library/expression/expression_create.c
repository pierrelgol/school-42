/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expression_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:47:16 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/06 18:47:17 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

t_expression	*expression_create(void)
{
	t_expression	*self;

	self = memory_alloc(sizeof(t_expression));
	if (!self)
		return (NULL);
	self->is_complete = false;
	self->kind = EXPR_UNKOWN;
	self->size = 0;
	self->tokens = list_create();
	return (self);
}

uintptr_t	expression_ctor(uintptr_t expr)
{
	t_expression	*input;
	t_expression	*clone;

	input = (t_expression *)expr;
	clone = expression_create();
	if (!input)
		return ((uintptr_t)clone);
	list_copy(clone->tokens, input->tokens, token_ctor);
	clone->is_complete = false;
	clone->kind = EXPR_UNKOWN;
	clone->size = list_size(clone->tokens);
	return ((uintptr_t)clone);
}
