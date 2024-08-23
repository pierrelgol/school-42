/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:36:11 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/13 10:36:14 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	return (nb * ft_recursive_factorial(nb - 1));
}
// #include <stdlib.h>
// #include <stdio.h>
// int main(int argc, char **argv)
// {
// 	if (argc == 2)
// 		printf("The factorial of %d is %d\n",atoi(argv[1])
//  , ft_recursive_factorial(atoi(argv[1])));
// 	return (0);
// }