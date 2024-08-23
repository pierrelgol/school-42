/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierreollivier <plgol.perso@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:34:56 by pierreollivie     #+#    #+#             */
/*   Updated: 2023/07/07 17:35:02 by pierreollivie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret;
	size_t	ret_len;
	size_t	i;

	ret_len = 0;
	while (s[ret_len] != '\0')
		ret_len++;
	ret = (char *)malloc(sizeof(char) * ret_len + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (i < ret_len)
	{
		ret[i] = f(i, s[i]);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
