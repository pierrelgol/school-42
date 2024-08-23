/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:36:38 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/13 10:36:39 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	else
		return (nb * ft_recursive_power(nb, (power - 1)));
}
// #include <stdlib.h>
// #include <stdio.h>
// int main(int argc, char **argv)
// {
// 	if (argc == 3)
// 	{
// 		int nbr = atoi(argv[1]);	
// 		int pow = atoi(argv[2]);	
// 		int result = ft_recursive_power(nbr, pow);
// 		printf("%d to the power of %d is %d\n",nbr, pow, result);
// 	}
// 	return (0);
// }