/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:36:25 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/13 10:45:24 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	result;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	result = nb;
	while (--power > 0)
		result *= nb;
	return (result);
}
// #include <stdlib.h>
// #include <stdio.h>
// int main(int argc, char **argv)
// {
// 	if (argc == 3)
// 	{
// 		int nbr = atoi(argv[1]);	
// 		int pow = atoi(argv[2]);	
// 		int result = ft_iterative_power(nbr, pow);
// 		printf("%d to the power of %d is %d\n",nbr, pow, result);
// 	}
// 	return (0);
// }