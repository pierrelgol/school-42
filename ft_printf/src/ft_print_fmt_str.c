/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_fmt_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:49:52 by pollivie          #+#    #+#             */
/*   Updated: 2023/11/03 17:49:54 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_printf.h"

static t_i32	ft_strlen(t_i8 *str)
{
	t_i8	*pstr;

	pstr = str;
	while (*pstr)
		++pstr;
	return (pstr - str);
}

t_i32	ft_print_fmt_str(va_list *arg)
{
	t_i8	*str;

	str = va_arg(*arg, t_i8 *);
	if (str == NULL)
		return (write(1, "(null)", 6));
	else
		return (write(1, str, ft_strlen(str)));
}
