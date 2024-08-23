/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_exe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 09:52:29 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/07 09:52:30 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *string_join_sep(const char *const beg, const char sep, const char *end)
{
	char    *result;
	char    *inter;
	uint64_t blen;
	uint64_t elen;
	uint64_t size;

	inter = (char[2]){sep, '\0'};
	blen = string_length(beg);
	elen = string_length(end);
	size = blen + elen + 1;
	result = memory_alloc(size + 1);
	if (!result)
		return (NULL);
	string_concat(result, beg, size + 1);
	string_concat(result, inter, size + 1);
	string_concat(result, end, size + 1);
	return (result);
}

bool resolve_exe(t_resolver *self, t_token *maybe_exe)
{
	char *test_path;
	char *path;

	if (access(maybe_exe->string, X_OK) == 0)
	{
		token_set_kind(maybe_exe, KIND_CMD);
		return (true);
	}
	it_save(self->it);
	while (!it_end(self->it))
	{
		test_path = it_peek_curr(self->it);
		path = string_join_sep(test_path, '/', token_get_str(maybe_exe));
		if (access(path, X_OK) == 0)
		{
			token_set_str(maybe_exe, path);
			token_set_kind(maybe_exe, KIND_CMD);
			memory_dealloc(path);
			return (it_restore(self->it), true);
		}
		memory_dealloc(path);
		it_advance(self->it);
	}
	return (it_restore(self->it), false);
}
