/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envmap_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:48:36 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/06 14:48:37 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	envmap_set(t_envmap *const self, char *key, char *value)
{
	hashmap_put(self->map, key, (uintptr_t)value);
	return (true);
}
