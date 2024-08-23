/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_compare_uid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:56:37 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/04 12:56:39 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int64_t	token_compare_uid(uintptr_t tok1, uintptr_t tok2)
{
	t_token	*token1;
	t_token	*token2;

	token1 = (t_token *)tok1;
	token2 = (t_token *)tok2;
	if (token1 && token2)
		return (token1->uid == token2->uid);
	return (0);
}
