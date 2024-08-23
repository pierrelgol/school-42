/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:58:15 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/04 10:58:16 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

t_node	*node_destroy(t_node *const self)
{
	if (self)
		memory_dealloc(self);
	return (NULL);
}
