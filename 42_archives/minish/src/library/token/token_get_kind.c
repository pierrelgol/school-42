/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_get_kind.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:57:49 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/04 11:57:49 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token_kind	token_get_kind(t_token *const self)
{
	if (self)
		return (self->kind);
	return (KIND_NO_KIND);
}
