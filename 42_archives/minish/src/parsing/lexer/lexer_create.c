/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:30:59 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/04 16:31:00 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lexer	*lexer_create(t_list *const token_pool, t_envmap *const map)
{
	t_lexer	*self;

	self = (t_lexer *)memory_alloc(sizeof(t_lexer));
	if (!self)
		return (NULL);
	self->token_pool = token_pool;
	self->map = map;
	self->it = NULL;
	self->is_dirty = false;
	return (self);
}
