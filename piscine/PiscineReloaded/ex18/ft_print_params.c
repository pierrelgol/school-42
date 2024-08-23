/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:07:43 by pollivie          #+#    #+#             */
/*   Updated: 2023/10/30 16:10:40 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char ch);

int	ft_strlen(char *str)
{
	char	*pstr;

	pstr = str;
	while (*pstr)
		++pstr;
	return (pstr - str);
}

int	main(int argc, char **argv)
{
	int	count;
	int	len;
	int	i;

	if (argc >= 2)
	{
		count = 1;
		while (count < argc)
		{
			len = ft_strlen(argv[count]);
			i = 0;
			while (i < len)
				ft_putchar(argv[count][i++]);
			ft_putchar('\n');
			++count;
		}
	}
	return (0);
}
