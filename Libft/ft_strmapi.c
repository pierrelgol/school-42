/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:58:20 by pollivie          #+#    #+#             */
/*   Updated: 2023/10/02 11:58:21 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*result;
	int		rlen;
	int		i;

	if (!s || !f)
		return (NULL);
	rlen = ft_strlen(s);
	result = (char *)malloc(sizeof(char) * rlen + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (*s)
	{
		result[i] = f(i, *s++);
		++i;
	}
	result[rlen] = '\0';
	return (result);
}
