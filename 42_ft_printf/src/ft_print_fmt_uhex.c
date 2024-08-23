/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_fmt_uhex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:50:14 by pollivie          #+#    #+#             */
/*   Updated: 2023/11/03 17:50:15 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_printf.h"

t_i32	ft_print_fmt_uhex(va_list *arg)
{
	t_u32	lhex;

	lhex = va_arg(*arg, t_u32);
	return (ft_uputnbr_base((t_u32)lhex, (t_i8 *)"0123456789ABCDEF", 16));
}
