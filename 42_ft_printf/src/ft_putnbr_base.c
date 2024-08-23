/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:52:01 by pollivie          #+#    #+#             */
/*   Updated: 2023/11/03 17:52:01 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_printf.h"

t_i32	ft_uputnbr_base(t_u64 num, t_i8 *base, t_i32 radix)
{
	t_i32	i;
	t_i32	len;
	t_i8	result[64];

	len = 0;
	if (num < 0)
	{
		len += write(1, "-", 1);
		num = -num;
	}
	i = 0;
	while (num > 0)
	{
		result[i] = base[num % radix];
		num /= radix;
		i++;
	}
	if (i == 0)
		len += write(1, "0", 1);
	else
	{
		while (i > 0)
			len += write(1, &result[--i], 1);
	}
	return (len);
}

t_i32	ft_iputnbr_base(t_i64 num, t_i8 *base, t_i32 radix)
{
	t_i32	i;
	t_i32	len;
	t_i8	result[64];

	len = 0;
	if (num < 0)
	{
		len += write(1, "-", 1);
		num = -num;
	}
	i = 0;
	while (num > 0)
	{
		result[i] = base[num % radix];
		num /= radix;
		i++;
	}
	if (i == 0)
		len += write(1, "0", 1);
	else
	{
		while (i > 0)
			len += write(1, &result[--i], 1);
	}
	return (len);
}
