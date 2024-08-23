/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 03:02:11 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/14 03:02:16 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	unsigned int	slen;
	unsigned int	i;
	char			*duplicata;

	if (src == NULL)
		return (NULL);
	slen = 0;
	while (src[slen])
		++slen;
	duplicata = (char *)malloc(sizeof(char) * slen + 1);
	if (duplicata == NULL)
		return (NULL);
	i = 0;
	while (*src)
		duplicata[i++] = *src++;
	duplicata[i] = '\0';
	return (duplicata);
}
/*#include <stdio.h>
#include <string.h>
#include <assert.h>
int main(int argc, char **argv)
{
	if(argc == 2)
	{
		char *duplicata = ft_strdup(argv[1]);
		char *test = strdup(argv[1]);
		assert(strcmp(duplicata, test) == 0);
		printf("ft_strdup : %s has been copied : %s\n",argv[1], duplicata);
		printf("strdup    : %s has been copied : %s\n",argv[1], test);
		if (duplicata)
			free(duplicata);
		if (test)
			free(test);
	}
	return (0);
}*/