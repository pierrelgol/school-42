/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:25:50 by pollivie          #+#    #+#             */
/*   Updated: 2023/10/30 15:25:51 by pollivie         ###   ########.fr       */
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
// int	main(int argc, char **argv)
// {
// 	if (argc == 2)
// 	{
// 		__builtin_printf("%s | %d\n", argv[1],
			// ft_recursive_factorial(atoi(argv[1])));
// 	}
// 	return (0);
// }
