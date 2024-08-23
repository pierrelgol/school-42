/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_join.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:00:58 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/04 12:00:59 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*token_join(const t_token *const tok1, const t_token *const tok2,
		const char *const sep)
{
	t_token	*result;
	char	*temp1;
	char	*temp2;

	if (sep != NULL)
	{
		temp1 = string_join(tok1->string, sep);
		temp2 = string_join(temp1, tok2->string);
		result = token_create();
		token_set_str(result, temp2);
		memory_dealloc(temp1);
		memory_dealloc(temp2);
	}
	else
	{
		temp1 = string_join(tok1->string, tok2->string);
		result = token_create();
		token_set_str(result, temp1);
		memory_dealloc(temp1);
	}
	return (result);
}
