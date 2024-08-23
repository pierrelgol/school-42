/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_fmt_lhex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:49:38 by pollivie          #+#    #+#             */
/*   Updated: 2023/11/03 17:49:39 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_printf.h"

t_i32	ft_print_fmt_lhex(va_list *arg)
{
	t_u32	lhex;

	lhex = va_arg(*arg, t_u32);
	return (ft_uputnbr_base((t_u32)lhex, (t_i8 *)"0123456789abcdef", 16));
}
