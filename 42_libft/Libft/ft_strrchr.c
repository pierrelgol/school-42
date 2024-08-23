/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:55:39 by pollivie          #+#    #+#             */
/*   Updated: 2023/10/02 11:55:40 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*ptr_s;
	const char	*ptr_c;

	ptr_s = s;
	ptr_c = NULL;
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (*ptr_s)
	{
		if (*ptr_s == (char)c)
			ptr_c = ptr_s;
		++ptr_s;
	}
	return ((char *)ptr_c);
}
