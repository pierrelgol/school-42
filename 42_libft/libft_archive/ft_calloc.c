/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierreollivier <plgol.perso@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:50:20 by pierreollivie     #+#    #+#             */
/*   Updated: 2023/07/07 11:50:25 by pierreollivie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;

	ret = (void *)malloc(count * size);
	if (!ret)
		return (NULL);
	ft_bzero(ret, count * size);
	return (ret);
}
