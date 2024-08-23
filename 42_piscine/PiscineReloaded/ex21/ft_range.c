/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:25:36 by pollivie          #+#    #+#             */
/*   Updated: 2023/10/30 16:25:37 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int		*range;
	long	size;
	int		i;

	if (min >= max)
		return (NULL);
	else if (min < 0 && max > 0)
		size = max + (-min);
	else
		size = max - min;
	range = (int *)malloc(sizeof(int) * (size + 1));
	if (range == NULL)
		return (NULL);
	i = 0;
	while (min < max)
		range[i++] = min++;
	return (range);
}
/*#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		int min = atoi(argv[1]);
		int max = atoi(argv[2]);
		int *res = ft_range(min, max);
		if ((min == 0 && max == 0 ) || (min >= max))
			assert(res == NULL);
		if (res)
		{
			for (int i = 0; i + 1 <= (max - min); ++i)
				printf("%d, ",res[i]);
			printf("\n");
			if (res)
				free(res);
		}
	}
}*/
