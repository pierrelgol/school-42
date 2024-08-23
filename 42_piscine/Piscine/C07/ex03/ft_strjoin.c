/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 00:01:19 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/16 00:01:21 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>


int	ft_strlen(char *str)
{
	char	*ps;

	ps = str;
	while (*ps)
		++ps;
	return (ps - str);
}

char	*ft_strcat(char *dest, char *src)
{
	int	index;

	index = ft_strlen(dest);
	while (*src)
		dest[index++] = *src++;
	dest[index] = '\0';
	return (dest);
}

int	ft_get_length(int size, char **strs, char *sep)
{
	int	length;
	int	index;

	length = 0;
	index = 0;
	if (size <= 0)
		return (1);
	while (index < size)
		length += ft_strlen(strs[index++]);
	length += ft_strlen(sep) * (size - 1);
	return (length);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		rlen;
	int		index;

	rlen = ft_get_length(size, strs, sep);
	result = malloc(sizeof(char) * rlen + 1);
	if (!result)
		return (NULL);
	index = 0;
	result[0] = '\0';
	while (index < size)
	{
		result = ft_strcat(result, strs[index]);
		if ((index + 1) < size)
			result = ft_strcat(result, sep);
		++index;
	}
	result[rlen] = '\0';
	return (result);
}


#include <stdio.h>
#include <stdlib.h>
int	main(int argc, char **argv)
{
	char	**split;
	int		index;
	char	*sep;
	char	*result;

	if (argc >= 3)
	{
		split = (char **)malloc(sizeof(char *) * (argc - 1));
		for (index = 1; index < argc - 1; index++)
			split[index - 1] = argv[index];
		sep = argv[argc - 1];
		result = ft_strjoin(argc - 2, split, sep);
		printf("1:%s\n", result);
		free(result);
		result = ft_strjoin(0, split, sep);
		printf("2:%s\n", result);
		free(result);
		free(split);
	}
	return (0);
}
