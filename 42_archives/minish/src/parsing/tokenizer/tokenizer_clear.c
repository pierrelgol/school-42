/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 06:50:02 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/05 06:50:03 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	tokenizer_clear(t_tokenizer *const self)
{
	if (!self || !self->is_dirty)
		return (false);
	self->tokens = string_split_destroy(self->tokens);
	self->is_dirty = false;
	return (true);
}
