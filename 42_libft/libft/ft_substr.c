/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:56:58 by pollivie          #+#    #+#             */
/*   Updated: 2023/10/02 11:56:59 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*result;
	unsigned int	slen;
	unsigned int	i;

	if (!s)
		return (NULL);
	i = 0;
	slen = ft_strlen(s);
	result = (char *) malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	if (start <= slen)
	{
		while (len-- && s[start + i])
		{
			result[i] = s[start + i];
			++i;
		}
	}
	result[i] = '\0';
	return (result);
}
