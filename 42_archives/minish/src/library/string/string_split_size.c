/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_split_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:07:18 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/04 12:07:19 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

uint64_t	split_size(char **split)
{
	uint64_t	i;

	if (!split || !*split)
		return (0);
	i = 0;
	while (split[i])
		++i;
	return (i);
}
