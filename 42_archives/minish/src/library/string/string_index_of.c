/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_index_of.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:21:32 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/30 10:21:33 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

int64_t	string_index_of(const char *const source, const int32_t ch)
{
	const uint64_t	slen = string_length(source);

	const char *const result = memory_search(source, ch, slen);
	if (!result)
		return (-1);
	return (result - source);
}
