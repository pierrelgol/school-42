/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:29:55 by pollivie          #+#    #+#             */
/*   Updated: 2023/10/30 15:29:55 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define EPSILON 0.00001

double	ft_fabs(double n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_sqrt(int nb)
{
	double	guess;

	if (nb < 0)
		return (0);
	if (nb == 1)
		return (1);
	guess = (nb * 0.5);
	while (ft_fabs(guess * guess) - nb > EPSILON)
	{
		guess = 0.5 * (guess + nb / guess);
	}
	if ((int)guess == (float)guess)
		return (guess);
	return (0);
}

// #include <stdlib.h>

// int	main(int argc, char **argv)
// {
// 	if (argc == 2)
// 	{
// 		__builtin_printf("sqrt(%d) ==  %d\n",atoi(argv[1]),
			// ft_sqrt(atoi(argv[1])));
// 	}
// 	return (0);
// }
