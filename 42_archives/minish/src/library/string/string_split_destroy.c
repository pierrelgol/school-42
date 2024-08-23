/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_split_destroy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:06:20 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/04 12:06:20 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

char	**string_split_destroy(char **split)
{
	uint64_t	i;

	if (!split)
		return (NULL);
	i = 0;
	while (split[i])
		memory_dealloc(split[i++]);
	memory_dealloc(split);
	return (NULL);
}
