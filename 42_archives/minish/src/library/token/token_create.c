/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:53:14 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/04 11:53:14 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*token_endtok(void)
{
	t_token	*token;

	token = token_create();
	token->string = string_clone("");
	token->len = 0;
	token->kind = KIND_END_TOKEN;
	return (token);
}

t_token	*token_create(void)
{
	static uint64_t	uid;
	t_token			*self;

	self = (t_token *)memory_alloc(sizeof(t_token));
	if (!self)
		return (NULL);
	self->uid = uid++;
	self->kind = KIND_NO_KIND;
	self->len = 0;
	self->string = NULL;
	return (self);
}

uintptr_t	token_ctor(uintptr_t token)
{
	t_token	*result;
	t_token	*tok;

	tok = (t_token *)token;
	result = token_create();
	if (!tok)
		return ((uintptr_t)result);
	token_set_str(result, tok->string);
	token_set_kind(result, tok->kind);
	return ((uintptr_t)result);
}
