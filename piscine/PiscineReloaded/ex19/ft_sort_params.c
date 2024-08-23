/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:13:41 by pollivie          #+#    #+#             */
/*   Updated: 2023/10/30 16:13:42 by pollivie         ###   ########.fr       */
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

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		++s1;
		++s2;
	}
	return (*s1 - *s2);
}

void	ft_sort(int argc, char **argv)
{
	char	*temp;
	int		i;

	i = 2;
	while (i < argc)
	{
		while (i >= 2 && ft_strcmp(argv[i - 1], argv[i]) > 0)
		{
			temp = argv[i];
			argv[i] = argv[i - 1];
			argv[i - 1] = temp;
			--i;
		}
		++i;
	}
}

int	main(int argc, char **argv)
{
	int	count;
	int	len;
	int	i;

	if (argc >= 2)
	{
		ft_sort(argc, argv);
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
