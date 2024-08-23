/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 03:57:03 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/28 03:57:08 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (0);
	while (*s1 == *s2)
	{
		++s1;
		++s2;
	}
	return (*s1 - *s2);
}

void	ft_sort_string_tab(char **tab)
{
	char	*temp;
	int		i;

	if (!tab)
		return ;
	i = 1;
	while (tab[i])
	{
		while (i >= 1 && ft_strcmp(tab[i - 1], tab[i]) > 0)
		{
			temp = tab[i];
			tab[i] = tab[i - 1];
			tab[i - 1] = temp;
			--i;
		}
		++i;
	}
}

// #include <stdio.h>
// #include <stdlib.h>
// int	main(int argc, char **argv)
// {
// 	char **tab;
// 	int index;
// 	if (argc >= 3)
// 	{
// 		index = 1;
// 		tab = (char **) malloc(sizeof(char *) * argc);
// 		if (!tab)
// 			return (1);
// 		while (index < argc)
// 		{
// 			tab[index - 1] = argv[index];
// 			printf("tab[%d] = %s\n",index - 1, tab[index - 1]);
// 			++index;
// 		}
// 		printf("\n");
// 		tab[index] = NULL;
// 		ft_sort_string_tab(tab);
// 		index = 0;
// 		while (index < argc)
// 		{
// 			printf("tab[%d] = %s\n",index, tab[index]);
// 			++index;
// 		}
// 		free(tab);
// 	}
// 	return (0);
// }
