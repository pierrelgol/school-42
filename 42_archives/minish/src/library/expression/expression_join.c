/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expression_join.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:47:40 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/06 18:47:41 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

t_expression	*expression_join(t_expression *const expr1,
		t_expression *const expr2)
{
	t_expression	*self;

	self = expression_create();
	list_copy(self->tokens, expr1->tokens, token_ctor);
	list_copy(self->tokens, expr2->tokens, token_ctor);
	self->size = list_size(self->tokens);
	self->is_complete = false;
	self->kind = EXPR_UNKOWN;
	return (self);
}
