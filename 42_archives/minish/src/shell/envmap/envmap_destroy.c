/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envmap_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:52:23 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/04 15:52:23 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

uintptr_t	envmap_clear_kv(uintptr_t kv)
{
	if (kv != 0)
		memory_dealloc((char *)kv);
	return (0);
}

t_envmap	*envmap_destroy(t_envmap *const self)
{
	if (self)
	{
		list_clear(self->keys, envmap_clear_kv);
		list_clear(self->values, envmap_clear_kv);
		list_destroy(self->keys);
		list_destroy(self->values);
		hashmap_destroy(self->map);
		memory_dealloc(self);
	}
	return (NULL);
}
