/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:39:39 by pollivie          #+#    #+#             */
/*   Updated: 2023/10/03 15:39:42 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstadd_back(t_list **lst, t_list *node)
{
	register t_list	*itter;

	if (*lst)
	{
		itter = *lst;
		while (itter->next)
			itter = itter->next;
		itter->next = node;
	}
	else
		*lst = node;
}
