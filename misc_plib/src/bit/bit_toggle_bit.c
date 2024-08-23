/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_toggle_bit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:33:06 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 10:35:10 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"

unsigned int	bit_toggle_bit(unsigned int num, unsigned int pos)
{
	return (num ^ (1 << pos));
}
