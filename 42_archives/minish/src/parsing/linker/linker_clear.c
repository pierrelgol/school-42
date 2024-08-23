/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linker_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:47:23 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/05 09:47:23 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	linker_clear(t_linker *const self)
{
	if (!self || !self->is_dirty)
		return (false);
	list_clear(self->token_pool_linked, token_dtor);
	self->is_dirty = false;
	return (true);
}
