/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_compare_kind.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:00:06 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/04 12:00:07 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int64_t	token_compare_kind(uintptr_t tok1, uintptr_t tok2)
{
	t_token	*token1;
	t_token	*token2;

	token1 = (t_token *)tok1;
	token2 = (t_token *)tok2;
	if (!token1 || !tok2)
		return (0);
	return (token1->kind == token2->kind);
}
