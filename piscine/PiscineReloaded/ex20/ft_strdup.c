/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:21:46 by pollivie          #+#    #+#             */
/*   Updated: 2023/10/30 16:21:47 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*result;
	int		len;

	if (!src)
		return (NULL);
	len = 0;
	while (src[len])
		++len;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = '\0';
	len = 0;
	while (src[len])
	{
		result[len] = src[len];
		++len;
	}
	return (result);
}

// int	main(int argc, char **argv)
// {
// 	if (argc == 2)
// 	{
// 		char *dup = ft_strdup(argv[1]);
// 		__builtin_printf("%s\n",dup);
// 		free(dup);
// 	}
// 	return (0);
// }
