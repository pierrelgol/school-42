/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:54:17 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/04 11:54:18 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*token_destroy(t_token *const self)
{
	if (self)
	{
		if (self->string)
		{
			memory_dealloc(self->string);
			self->string = NULL;
		}
		memory_dealloc(self);
	}
	return (NULL);
}

uintptr_t	token_dtor(uintptr_t token)
{
	t_token	*tok;

	tok = (t_token *)token;
	if (tok)
		token_destroy(tok);
	return (0);
}
