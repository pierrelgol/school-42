/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 21:25:52 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/10 21:10:21 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(int n)
{
	return (n == ' ' || (n >= 9 && n <= 13));
}

int	ft_atoi(char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str && ft_isspace(*str))
		++str;
	while (*str && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			sign *= -1;
		++str;
	}
	while (*str && *str >= '0' && *str <= '9')
		result = *str++ - '0' + result * 10;
	return (result * sign);
}
// #include <stdio.h>
// int main(int ac, char *av[])
// {
// 	if(ac == 2)
// 		printf("%s = %d\n",av[1],ft_atoi(av[1]));
// 	return (0);
// }
