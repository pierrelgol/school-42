/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:57:42 by pollivie          #+#    #+#             */
/*   Updated: 2023/10/02 11:57:44 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_ch_in_set(const char ch, const char *set)
{
	const char	*ptr_set;

	ptr_set = set;
	while (*ptr_set)
		if (*ptr_set++ == ch)
			return (1);
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	const char	*ptr_s1;
	size_t		start;
	size_t		end;
	size_t		i;
	char		*result;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	ptr_s1 = s1;
	end = ft_strlen(s1);
	while (ptr_s1[start] && ft_ch_in_set(ptr_s1[start], set))
		start++;
	while (start < end && ft_ch_in_set(ptr_s1[end - 1], set))
		end--;
	result = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (start < end)
		result[i++] = ptr_s1[start++];
	result[i] = '\0';
	return (result);
}
