/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:44:51 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/07 13:44:53 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static inline int	ft_is_print(int c)
{
	return (c >= 32 && c <= 126);
}

static void	ft_whex(int n)
{
	if (n == 0)
	{
		write(1, "0", 1);
		return ;
	}
	ft_whex((n / 16));
	write(1, &"0123456789abcdef"[n % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (!(ft_is_print(*str)))
		{
			if (*str < 16)
				write(1, "\\", 2);
			ft_whex(*str);
		}
		else
			write(1, str, 1);
		++str;
	}
}
#include <assert.h>
#include <stdio.h>
#include <string.h>

// void	test_basic(void)
// {
// 	char str[] = "Coucou\ntu vas bien ?";
// 	ft_putstr_non_printable(str);
// }

// int	main(void)
// {
// 	test_basic();
// 	return (0);
// }  
int		main()
{
	char c[] = "Coucou\ntu vas bien ?";
	ft_putstr_non_printable(c);
	char d[] = "\x81\xbe";
	ft_putstr_non_printable(d);
}