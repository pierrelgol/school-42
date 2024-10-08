/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_is_empty.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:00:46 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/04 11:00:46 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

bool	list_is_empty(const t_list *const self)
{
	return (self->size == 0);
}
