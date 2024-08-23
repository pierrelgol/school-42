/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:38:37 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/13 10:38:38 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int		is_prime;
	long	lnb;
	long	i;

	lnb = nb;
	if (nb < 2)
		return (0);
	i = 2;
	is_prime = 1;
	while ((i * i) <= lnb && is_prime)
	{
		if (lnb % i == 0)
			is_prime = 0;
		++i;
	}
	return (is_prime);
}
// #include <stdio.h>
// #include <stdlib.h>
// int main(int argc, char **argv)
// {
//   if (argc == 2)
//   {
//     printf("the number %d %s\n",
// 			atoi(argv[1]), (ft_is_prime( atoi(argv[1])) == 1 ? 
// 			"is a prime number" : "is not a prime number"));
//   }
//   return (0);
// }