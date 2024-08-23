/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 21:26:12 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/08 21:26:22 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

static int	ft_parse_base(char *base)
{
	char	*set;
	int		len;
	int		i;

	i = 0;
	len = 0;
	set = (char [255]){0};
	while (base[len])
	{
		set[(int)base[len]]++;
		len++;
	}
	while ((set[i] <= 1) && (i < 255))
		++i;
	if (i != 255 || len == 0 || len == 1)
		return (0);
	if (set['-'] >= 1 || set['+'] >= 1)
		return (0);
	return (len);
}

static void	ft_write_rdx(long int nbr, int rdx, char *base)
{
	if (nbr == 0)
		return ;
	ft_write_rdx((nbr / rdx), rdx, base);
	write(1, &base[nbr % rdx], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long int	n;
	int			rdx;

	if (base == (void *)0 || *base == '\0')
		return ;
	n = nbr;
	rdx = ft_parse_base(base);
	if (rdx == 0)
		return ;
	if (n <= 0)
	{
		if (n == 0)
			write(1, &"0", 1);
		else
			write(1, &"-", 1);
		n *= -1;
	}
	ft_write_rdx(n, rdx, base);
}
// #include <stdio.h>
// #include <limits.h>
// int	ft_isspace(int n)
// {
// 	return (n == ' ' || (n >= 9 && n <= 13));
// }

// int	ft_atoi(char *str)
// {
// 	int	result;
// 	int	sign;

// 	result = 0;
// 	sign = 1;
// 	while (*str && ft_isspace(*str))
// 		++str;
// 	while (*str && (*str == '-' || *str == '+'))
// 	{
// 		if (*str == '-')
// 			sign *= -1;
// 		++str;
// 	}
// 	while (*str && *str >= '0' && *str <= '9')
// 		result = *str++ - '0' + result * 10;
// 	return (result * sign);
// }

// int main(int argc, char **argv)
// {
// 	if (argc == 3)
// 		ft_putnbr_base(ft_atoi(argv[1]), argv[2]);

// 	return (0);
// } 