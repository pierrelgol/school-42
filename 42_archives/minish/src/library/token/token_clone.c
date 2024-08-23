/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_clone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:11:12 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/04 12:11:12 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*token_clone(const t_token *const self)
{
	t_token	*result;

	result = token_create();
	if (!self)
		return (result);
	token_set_str(result, self->string);
	token_set_kind(result, self->kind);
	return (result);
}
