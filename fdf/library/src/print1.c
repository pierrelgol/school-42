/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:32:46 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/30 12:32:47 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "essentials.h"

int	put_char(va_list arg, int fd)
{
	int32_t	ch[1];

	ch[0] = (char)va_arg(arg, int32_t);
	return (write(fd, ch, 1));
}

int	put_string(va_list arg, int fd)
{
	char		*str;
	uint64_t	len;

	str = va_arg(arg, char *);
	if (!str)
		return (write(fd, "(null)", 6));
	len = string_length(str);
	return (write(fd, str, len));
}

int	put_int32(va_list arg, int fd)
{
	int32_t	num;

	num = va_arg(arg, int32_t);
	return (put_inumber_base(num, "0123456789", 10, fd));
}

int	put_ilong64(va_list arg, int fd)
{
	int64_t	num;

	num = va_arg(arg, int64_t);
	return (put_inumber_base(num, "0123456789", 10, fd));
}

int	put_ulong64(va_list arg, int fd)
{
	uint64_t	num;

	num = va_arg(arg, uint64_t);
	return (put_unumber_base(num, "0123456789", 10, fd));
}
