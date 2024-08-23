/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linker_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:37:01 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/04 16:37:01 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_linker	*linker_destroy(t_linker *const self)
{
	if (self)
	{
		if (self->is_dirty)
			linker_clear(self);
		memory_dealloc(self);
	}
	return (NULL);
}
