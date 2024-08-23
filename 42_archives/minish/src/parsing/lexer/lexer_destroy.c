/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:31:04 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/04 16:31:05 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lexer	*lexer_destroy(t_lexer *const self)
{
	if (self)
	{
		if (self->is_dirty)
			lexer_clear(self);
		memory_dealloc(self);
	}
	return (NULL);
}
