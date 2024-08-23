/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_starts_with.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:52:49 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/05 10:52:49 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

bool	string_starts_with(const char *const string,
		bool(predicate)(int32_t ch))
{
	return (string != NULL && predicate(string[0]));
}
