/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_contains.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:52:10 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/05 10:52:11 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

bool	string_contains(const char *const string, const char ch)
{
	return (string_index_of(string, ch) != -1);
}
