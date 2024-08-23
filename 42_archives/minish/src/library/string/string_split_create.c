/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_split_create.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:05:00 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/04 12:05:00 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

char	**string_split_create(const uint64_t size)
{
	char	**result;

	result = memory_alloc(sizeof(char *) * (size + 1));
	result[size] = NULL;
	return (result);
}
