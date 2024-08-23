/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_length.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:47:55 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/04 20:47:56 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

uint64_t	list_length(t_list *list)
{
	uint64_t	length;

	length = 0;
	while (list)
	{
		list = list->next;
		length++;
	}
	return (length);
}
