/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_reverse_bits.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:17:12 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 10:34:33 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"

unsigned int	bit_reverse_bits(unsigned int num)
{
	unsigned int	rev;
	int				bsize;

	bsize = (sizeof(num) << 3) - 1;
	rev = num;
	num >>= 1;
	while (num)
	{
		rev <<= 1;
		rev |= num & 1;
		num >>= 1;
		bsize--;
	}
	rev <<= bsize;
	return (rev);
}
