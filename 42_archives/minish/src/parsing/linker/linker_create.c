/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linker_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:36:48 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/04 16:36:48 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_linker	*linker_create(t_list *const token_pool, t_envmap *const envmap)
{
	t_linker	*self;

	self = (t_linker *)memory_alloc(sizeof(t_linker));
	if (!self)
		return (NULL);
	self->envmap = envmap;
	self->token_pool = token_pool;
	self->token_pool_linked = list_create();
	self->is_dirty = false;
	return (self);
}
