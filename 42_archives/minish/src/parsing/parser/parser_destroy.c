/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:31:28 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/04 16:31:29 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_parser	*parser_destroy(t_parser *const self)
{
	if (!self)
		return (NULL);
	if (self->is_dirty)
		parser_clear(self);
	list_destroy(self->expr_list);
	memory_dealloc(self);
	return (NULL);
}
