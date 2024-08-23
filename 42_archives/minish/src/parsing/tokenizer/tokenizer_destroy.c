/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_destroy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:30:40 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/04 16:30:40 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tokenizer	*tokenizer_destroy(t_tokenizer *self)
{
	if (self)
	{
		if (self->is_dirty)
			tokenizer_clear(self);
		memory_dealloc(self);
	}
	return (NULL);
}
