/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ascii.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:18:07 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/30 12:18:08 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/slib.h"

inline bool	is_ascii(const int32_t ch)
{
	return (ch >= 0 && ch <= 127);
}
