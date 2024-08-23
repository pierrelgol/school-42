/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:29:15 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/06 19:39:52 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

void	list_dump(t_list *const dest, t_list *const src)
{
	if (!dest || !src || list_is_empty(src))
		return ;
	while (!list_is_empty(src))
		list_insert_back(dest, list_remove_front(src));
}
