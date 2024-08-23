/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expression_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:47:26 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/06 18:47:26 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

t_expression	*expression_destroy(t_expression *const self)
{
	if (!self)
		return (NULL);
	list_clear(self->tokens, token_dtor);
	list_destroy(self->tokens);
	self->tokens = NULL;
	self->is_complete = false;
	self->kind = EXPR_UNKOWN;
	memory_dealloc(self);
	return (NULL);
}

uintptr_t	expression_dtor(uintptr_t self)
{
	t_expression	*expr;

	expr = (t_expression *)self;
	if (!expr)
		return (0);
	expression_destroy(expr);
	return (0);
}
