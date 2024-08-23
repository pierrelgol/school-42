/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_set_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:55:36 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/04 11:55:36 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	token_set_str(t_token *const self, const char *const string)
{
	if (!self || !string)
		return ;
	if (self->string)
		memory_dealloc(self->string);
	self->string = (char *)string_clone(string);
	self->len = string_length(string);
}
