/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:43:44 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/13 10:43:47 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(long nb)
{
	long	i;

	i = 2;
	if (nb < 2)
		return (0);
	while ((i * i) <= nb)
	{
		if (nb % i == 0)
			return (0);
		++i;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	long	i;

	i = nb;
	if (i == 2 || i < 0)
		return (2);
	while (!(ft_is_prime(i)))
		++i;
	return (i);
}
// #include <stdio.h>
// #include <stdlib.h>
// int main(int argc, char **argv)
// {
//   if (argc == 2)
//     printf("the closest prime number after %d is %d\n",
// atoi(argv[1]), ft_find_next_prime(atoi(argv[1])));
//   return (0);
// }