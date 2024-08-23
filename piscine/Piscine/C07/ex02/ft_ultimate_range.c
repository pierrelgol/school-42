/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 03:02:48 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/14 03:02:51 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	long	size;
	long	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	else if (min < 0 && max > 0)
		size = max + (-min);
	else
		size = max - min;
	*range = (int *)malloc(sizeof(int) * (size));
	if (*range == NULL)
	{
		*range = NULL;
		return (-1);
	}
	i = 0;
	while (min < max)
		(*range)[i++] = min++;
	return (size);
}
/*#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	if (argc == 3)
	{
		int min = atoi(argv[1]);
		int max = atoi(argv[2]);
		int *res = NULL;
		long size = ft_ultimate_range(&res, min, max);
		if ((size == -1) || (min == max) || (min > max))
			assert(res == NULL);
		for (int i = 0; i < size; ++i)
			printf("%d, ",res[i]);
		printf("\n");
		free(res);
	}
}*/