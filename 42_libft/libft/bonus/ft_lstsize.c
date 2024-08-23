/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:42:34 by pollivie          #+#    #+#             */
/*   Updated: 2023/10/03 15:42:36 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_lstsize(t_list *lst)
{
	register int	size;
	const t_list	*itter;

	size = 0;
	itter = lst;
	if (lst == NULL)
		return (0);
	while (itter)
	{
		itter = itter->next;
		++size;
	}
	return (size);
}
