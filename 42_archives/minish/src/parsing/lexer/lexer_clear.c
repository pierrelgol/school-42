/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:45:03 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/05 09:45:04 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	lexer_clear(t_lexer *const self)
{
	if (!self || !self->is_dirty)
		return (false);
	if (self->it)
		self->it = list_iter_destroy(self->it);
	self->is_dirty = false;
	return (true);
}
