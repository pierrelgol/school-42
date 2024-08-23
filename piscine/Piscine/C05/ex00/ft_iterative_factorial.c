/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:35:49 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/13 10:35:56 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	result;

	if (nb < 0)
		return (0);
	result = 1;
	while (nb > 0)
	{
		result *= nb--;
	}
	return (result);
}
// #include <stdlib.h>
// #include <stdio.h>
// int main(int argc, char **argv)
// {
// 	if (argc == 2)
// 		printf("The factorial of %d is %d\n",atoi(argv[1]),
// 		ft_iterative_factorial(atoi(argv[1])));
// 	return (0);
// }
