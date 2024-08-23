/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:57:21 by pollivie          #+#    #+#             */
/*   Updated: 2023/10/02 11:57:23 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	rlen;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	rlen = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * rlen + 1);
	if (!result)
		return (NULL);
	while (*s1)
		result[i++] = *s1++;
	while (*s2)
		result[i++] = *s2++;
	result[rlen] = '\0';
	return (result);
}
