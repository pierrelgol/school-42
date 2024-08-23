/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do-op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:24:05 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/25 13:24:07 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	do_putnbr(int nbr);
int		do_putstr(char *str);
int		do_atoi(char *nbr);
int		do_strcmp(char *s1, char *s2);

void	add(int n1, int n2)
{
	do_putnbr(n1 + n2);
}

void	mult(int n1, int n2)
{
	do_putnbr(n1 * n2);
}

void	div(int n1, int n2)
{
	if (n2 == 0)
		do_putstr("Stop : division by zero\n");
	else
		do_putnbr(n1 / n2);
}

void	mod(int n1, int n2)
{
	if (n2 == 0)
		do_putstr("Stop : modulo by zero\n");
	else
		do_putnbr(n1 % n2);
}

int	main(int argc, char **argv)
{
	void	(*opp[5])(int n1, int n2);

	(opp)[0] = add;
	(opp)[1] = mult;
	(opp)[2] = div;
	(opp)[3] = mod;
	if (argc == 4)
	{
		if (do_strcmp(argv[2], "+") == 0)
			opp[0](do_atoi(argv[1]), do_atoi(argv[3]));
		if (do_strcmp(argv[2], "-") == 0)
			opp[0](do_atoi(argv[1]), -(do_atoi(argv[3])));
		if (do_strcmp(argv[2], "*") == 0)
			opp[1](do_atoi(argv[1]), do_atoi(argv[3]));
		if (do_strcmp(argv[2], "/") == 0)
			opp[2](do_atoi(argv[1]), do_atoi(argv[3]));
		if (do_strcmp(argv[2], "%") == 0)
			opp[3](do_atoi(argv[1]), do_atoi(argv[3]));
	}
	return (0);
}
