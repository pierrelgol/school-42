/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_rotate_left.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:16:05 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 10:34:40 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"

unsigned int	bit_rotate_left(unsigned int num, unsigned int shift)
{
	shift %= sizeof(num) << 3;
	return ((num << shift) | (num >> ((sizeof(num) << 3) - shift)));
}
