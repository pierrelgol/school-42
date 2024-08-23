/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreted_destroy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:33:34 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/09 13:33:35 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

t_interpreted *interpreted_destroy(t_interpreted *const self)
{
	if (!self)
		return (NULL);
	self->cmd_table = cmd_table_destroy(self->cmd_table);
	if (self->maybe_file)
		memory_dealloc(self->maybe_file);
	memory_dealloc(self);
	return (NULL);
}
