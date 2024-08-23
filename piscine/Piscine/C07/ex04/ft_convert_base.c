/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 09:30:19 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/19 09:30:21 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int		ft_intlen(long nbr, int radix);
char	*ft_itoa_base(long nbr, char *base);
void	ft_init_sign(char *result, long nbr, short sign);
void	ft_putnbr_base(long nbr, short radix, char *base, char *result);

int	ft_parse_base(char *base)
{
	int		radix;
	int		index;
	char	*set;

	radix = 0;
	set = (char [255]){0};
	while (base[radix])
		set[(int)(base[radix++])] += 1;
	if (radix < 2 || set['-'] >= 1 || set['+'] >= 1)
		return (0);
	index = 0;
	while (index < 255 && set[index] <= 1)
	{
		if ((index < ' ' || index > '~') && (set[index] >= 1))
			return (0);
		++index;
	}
	if (index != 255)
		return (0);
	return (radix);
}

int	ft_base_at(char ch, char *base)
{
	int	index;

	index = 0;
	while (base[index] && base[index] != ch)
		++index;
	if (base[index] == '\0')
		return (-1);
	return (index);
}

int	ft_atoi_base(char *nbr, char *base)
{
	long	result;
	short	radix;
	short	sign;

	if (!nbr || !base)
		return (0);
	radix = ft_parse_base(base);
	if (radix == 0)
		return (0);
	while (*nbr && (*nbr == ' ' || (*nbr >= 9 && *nbr <= 13)))
		++nbr;
	sign = 1;
	while (*nbr && (*nbr == '-' || *nbr == '+'))
		if (*nbr++ == '-')
			sign *= -1;
	result = 0;
	while (*nbr && ft_base_at(*nbr, base) != -1)
		result = (ft_base_at(*nbr++, base) % radix) + (result * radix);
	return (result * sign);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	number;
	char	*result;

	if (!nbr || !base_from || !base_to)
		return (NULL);
	if (ft_parse_base(base_from) == 0 || ft_parse_base(base_to) == 0)
		return (NULL);
	number = ft_atoi_base(nbr, base_from);
	result = ft_itoa_base(number, base_to);
	return (result);
}

// #include <stdio.h>
// int	main(int argc, char **argv)
// {
// 	char *result;

// 	if (argc == 4)
// 	{
// 		result = ft_convert_base(argv[1], argv[2], argv[3]);
// 		printf("number    = %s\n", argv[1]);
// 		printf("base_from = %s\n", argv[2]);
// 		printf("base_to   = %s\n", argv[3]);
// 		printf("result    = %s\n", result);
// 		if (result)
// 			free(result);
// 	}
// 	return (0);
// }