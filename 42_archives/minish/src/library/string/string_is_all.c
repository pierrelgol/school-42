/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_is_all.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:54:47 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/05 10:54:47 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

bool	string_is_all(const char *const string, bool(predicate)(int32_t ch))
{
	uint64_t	index;

	if (!string)
		return (false);
	index = 0;
	while (string[index] && predicate(string[index]))
		++index;
	return (string[index] == '\0');
}
