/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:37:00 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/13 10:38:05 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
double	ft_fabs(double x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	ft_sqrt(int nb)
{
	double	epsilon;
	double	x;

	if (nb <= 0)
		return (0);
	x = nb * 0.5;
	epsilon = 0.00001;
	while (ft_fabs((x * x) - nb) > epsilon)
		x = 0.5 * (x + nb / x);
	if ((int)x == (float)x)
		return (x);
	else
		return (0);
}
// #include <stdio.h>
// #include <stdlib.h>
// int main(int argc, char **argv)
// {
// 	if (argc == 2)
// 	{
// 		int input = atoi(argv[1]);
// 		int sqrt = ft_sqrt(input);
// 		if (sqrt != 0)
// 			printf("Square Root of %d is :   %d and is a valid answer\n", input,
//				sqrt);
// 		else
// 			printf("Square Root of %d is :   %d and is an invalid answer\n",
//				input,sqrt);
// 	}
// 	return (0);
// }%  
