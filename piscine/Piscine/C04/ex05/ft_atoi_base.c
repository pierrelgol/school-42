/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:06:06 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/11 11:06:20 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_compute_base(char ch, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (ch == base[i])
			return (i);
		++i;
	}
	return (-1);
}

int	ft_isspace(int n)
{
	return (n == ' ' || (n >= 9 && n <= 13));
}

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
	if (set['-'] >= 1 || set['+'] >= 1 || set[' '] >= 1)
		return (0);
	return (len);
}

int	ft_atoi_convert(char *str, char *base, int sign, int radix)
{
	int	result;

	result = 0;
	while (*str)
	{
		if (ft_compute_base(*str, base) == -1)
			return (result);
		result = ft_compute_base(*str++, base) + (result * radix);
	}
	return (result * sign);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	radix;

	sign = 1;
	radix = ft_parse_base(base);
	if (radix == 0)
		return (0);
	while (*str && ft_isspace(*str))
		++str;
	while (*str && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			sign *= -1;
		++str;
	}
	return (ft_atoi_convert(str, base, sign, radix));
}
// #include <stdio.h>
// int main(int ac, char *av[])
// {
// 	if(ac == 3)
// 		printf("%s = %d\n",av[1],ft_atoi_base(av[1], av[2]));
// 	return (0);
// }