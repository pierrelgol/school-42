/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:56:26 by pollivie          #+#    #+#             */
/*   Updated: 2023/10/02 11:56:27 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	rlen;
	char	*result;

	rlen = -1;
	while (s1[++rlen])
		;
	result = (char *)malloc(sizeof(char) * rlen + 1);
	if (!result)
		return (NULL);
	rlen = 0;
	while (*s1)
		result[rlen++] = *s1++;
	result[rlen] = '\0';
	return (result);
}
