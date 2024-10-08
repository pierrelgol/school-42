/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_left_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:11:50 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/05 11:11:51 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

inline bool	is_left_redir(const int32_t ch)
{
	return (ch == '<');
}
