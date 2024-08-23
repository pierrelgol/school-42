/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:30:33 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/04 16:30:34 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tokenizer	*tokenizer_create(t_list *token_pool)
{
	t_tokenizer	*self;

	self = (t_tokenizer *)memory_alloc(sizeof(t_tokenizer));
	if (!self)
		return (NULL);
	self->token_pool = token_pool;
	self->is_dirty = false;
	self->tokens = NULL;
	return (self);
}
