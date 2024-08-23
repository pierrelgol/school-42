/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_table_destroy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:29:36 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/08 14:29:36 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

t_cmd_table *cmd_table_destroy(t_cmd_table *const self)
{
	if (!self)
		return (NULL);
	if (self->cmd_argv)
		string_split_destroy(self->cmd_argv);
	if (self->cmd_basename)
		memory_dealloc(self->cmd_basename);
	memory_dealloc(self);
	return (NULL);
}

