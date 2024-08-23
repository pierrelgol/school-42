/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_wlength.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:07:06 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/10 13:07:07 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

uint64_t	string_wlength_scalar(const char *source, const int32_t scalar)
{
	uint64_t	i;

	if (!source)
		return (0);
	i = string_count_leading_scalar(source, scalar);
	return (string_count_until_scalar(&source[i], scalar));
}

uint64_t	string_wlength_any(const char *source, const t_bitset *delimiters)
{
	uint64_t	i;

	if (!source)
		return (0);
	i = string_count_leading_any(source, delimiters);
	return (string_count_until_any(&source[i], delimiters));
}

uint64_t	string_wlength_none(const char *source, const t_bitset *delimiters)
{
	uint64_t	i;

	if (!source)
		return (0);
	i = string_count_leading_none(source, delimiters);
	return (string_count_until_none(&source[i], delimiters));
}

uint64_t	string_wlength_predicate(const char *source,
		bool(predicate)(int32_t ch))
{
	uint64_t	i;

	if (!source)
		return (0);
	i = string_count_leading_predicate(source, predicate);
	return (string_count_until_predicate(&source[i], predicate));
}

uint64_t	string_wlength_sequence(const char *source, const char *sequence)
{
	uint64_t	i;

	if (!source)
		return (0);
	i = string_count_leading_sequence(source, sequence)
		* string_length(sequence);
	return (string_count_until_sequence(&source[i], sequence));
}
