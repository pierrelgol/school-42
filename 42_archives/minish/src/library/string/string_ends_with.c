/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_ends_with.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:53:48 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/05 10:53:49 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

bool	string_ends_with(const char *const string, bool(predicate)(int32_t ch))
{
	uint64_t	len;

	len = string_length(string);
	if (len >= 1)
		return (predicate(string[len - 1]));
	return (false);
}
