/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_peek_at.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:00:05 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 11:00:07 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

uintptr_t	list_peek_at(t_list **list, uint64_t index)
{
	t_list	*result;

	result = list_get_at(list, index);
	if (!result)
		return (UINTPTR_MAX);
	return (result->data);
}
