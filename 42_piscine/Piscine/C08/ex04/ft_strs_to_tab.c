/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:18:33 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/18 11:18:35 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_stock_str.h"
#include <stdlib.h>

int					ft_strlen(char *str);
char				*ft_strcpy(char *dest, char *src);
struct s_stock_str	*ft_strs_to_tab(int ac, char **av);

int	ft_strlen(char *str)
{
	char	*pstr;

	if (str != (void *)0)
	{
		pstr = str;
		while (*pstr)
			++pstr;
		return (pstr - str);
	}
	return (0);
}

char	*ft_strdup(char *src, int slen)
{
	char	*ret;
	int		i;

	ret = (char *)malloc(sizeof(char) * slen + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (*src)
		ret[i++] = *src++;
	ret[slen] = '\0';
	return (ret);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*result;
	int					i;

	result = malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		result[i].str = av[i];
		result[i].size = ft_strlen(av[i]);
		result[i].copy = ft_strdup(av[i], result[i].size);
		++i;
	}
	result[i].str = 0;
	result[i].copy = 0;
	result[i].size = 0;
	return (result);
}
