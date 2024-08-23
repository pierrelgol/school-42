/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:54:46 by pollivie          #+#    #+#             */
/*   Updated: 2023/10/02 11:54:48 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char	*ptr_s;

	ptr_s = s;
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (*ptr_s && *ptr_s != (char)c)
		++ptr_s;
	if (*ptr_s == '\0')
		return (NULL);
	return ((char *)ptr_s);
}
