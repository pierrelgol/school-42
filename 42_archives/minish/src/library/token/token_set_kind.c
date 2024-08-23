/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_set_kind.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:56:22 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/04 11:56:22 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	token_set_kind(t_token *const self, const t_token_kind kind)
{
	if (!self)
		return ;
	self->kind = kind;
}
