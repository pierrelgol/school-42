/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_special.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:13:17 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/05 11:13:18 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

inline bool	is_special(const int32_t ch)
{
	return (ch != '|' && ch != '>' && ch != '<' && ch != '&' && ch != ';');
}
