/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_upper.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:50:55 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/30 12:51:00 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

inline bool	is_upper(const int32_t ch)
{
	return (ch >= 'A' && ch <= 'Z');
}
