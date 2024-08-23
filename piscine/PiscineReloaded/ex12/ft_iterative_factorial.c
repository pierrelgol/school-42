/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:29:11 by pollivie          #+#    #+#             */
/*   Updated: 2023/10/30 13:31:07 by pollivie         ###   ########.fr       */
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
// int	main(int argc, char **argv)
// {
// 	if (argc == 2)
// 	{
// 		__builtin_printf("%s == %d\n",argv[1],
			// ft_iterative_factorial(atoi(argv[1])));
// 	}
// 	return (0);
// }
