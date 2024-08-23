/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_pad.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 12:43:27 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/11 12:43:28 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

char	*string_pad_left_scalar(t_allocator *const allocator,
		const char *string, const int32_t scalar, const uint64_t amount)
{
	char		*result;
	uint64_t	len;
	uint64_t	i;

	len = string_length(string) + 1 * amount;
	result = allocator->create(allocator, len + 1);
	i = 0;
	while (i < amount)
	{
		string_append_scalar(result, scalar, len + 1);
		++i;
	}
	string_append_sequence(result, string, len + 1);
	return (result);
}

char	*string_pad_left_sequence(t_allocator *const allocator,
		const char *string, const char *sequence, const uint64_t amount)
{
	char		*result;
	uint64_t	len;
	uint64_t	i;

	len = string_length(string) + (string_length(sequence) * amount);
	result = allocator->create(allocator, len + 1);
	i = 0;
	while (i < amount)
	{
		string_append_sequence(result, sequence, len + 1);
		++i;
	}
	string_append_sequence(result, string, len + 1);
	return (result);
}

char	*string_pad_right_scalar(t_allocator *const allocator,
		const char *string, const int32_t scalar, const uint64_t amount)
{
	char		*result;
	uint64_t	len;
	uint64_t	i;

	len = string_length(string) + 1 * amount;
	result = allocator->create(allocator, len + 1);
	i = 0;
	string_append_sequence(result, string, len + 1);
	while (i < amount)
	{
		string_append_scalar(result, scalar, len + 1);
		++i;
	}
	return (result);
}

char	*string_pad_right_sequence(t_allocator *const allocator,
		const char *string, const char *sequence, const uint64_t amount)
{
	char		*result;
	uint64_t	len;
	uint64_t	i;

	len = string_length(string) + (string_length(sequence) * amount);
	result = allocator->create(allocator, len + 1);
	i = 0;
	string_append_sequence(result, string, len + 1);
	while (i < amount)
	{
		string_append_sequence(result, sequence, len + 1);
		++i;
	}
	return (result);
}
