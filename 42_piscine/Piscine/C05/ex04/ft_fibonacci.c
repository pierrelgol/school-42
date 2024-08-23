/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:36:50 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/13 10:36:52 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fib(int index)
{
	if (index <= 1)
		return (index);
	else
		return (ft_fib(index - 1) + ft_fib(index - 2));
}

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	return (ft_fib(index));
}
// #include <stdio.h>
// #include <stdlib.h>
// int main(int argc, char **argv)
// {
// 	if(argc == 2)
// 		printf("the index %d, in the fibonnacci series is %d\n",
// 	atoi(argv[1]),ft_fibonacci(atoi(argv[1])));
// 	return (0);
// }