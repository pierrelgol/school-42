/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_compare_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:58:31 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/04 11:58:32 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int64_t	token_compare_string(uintptr_t tok1, uintptr_t tok2)
{
	t_token	*token1;
	t_token	*token2;

	token1 = (t_token *)tok1;
	token2 = (t_token *)tok2;
	if (!token1 || !tok2)
		return (0);
	return (string_compare(token1->string, token2->string) == 0);
}
