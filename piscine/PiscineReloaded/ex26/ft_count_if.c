/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:13:57 by pollivie          #+#    #+#             */
/*   Updated: 2023/10/30 17:14:01 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int (*f)(char *))
{
	int	count;
	int	i;

	if (!tab)
		return (0);
	i = 0;
	count = 0;
	while (tab[i])
	{
		if (f(tab[i]))
			++count;
		++i;
	}
	return (count);
}

// #include <unistd.h>
// int ft_putchar(char *ch)
// {
// 	return (write(1, ch, 1));
// }

// int	main(int argc, char **argv)
// {
// 	if (argc == 2)
// 	{
// 		int	count;

// 		count = ft_count_if(&argv[1], ft_putchar);
// 		__builtin_printf("\n%d\n",count);
// 	}

// 	return (0);
// }
