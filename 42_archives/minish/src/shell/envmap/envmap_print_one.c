/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envmap_print_one.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:05:59 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/04 16:05:59 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	envmap_print_one(t_envmap *const self, char *key)
{
	char	*value;

	value = (char *)hashmap_get(self->map, key);
	if (value != NULL)
	{
		printf("%s=%s\n", key, value);
	}
}
