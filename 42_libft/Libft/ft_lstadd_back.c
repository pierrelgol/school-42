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

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *node)
{
	t_list	*temp;

	if (*lst == NULL)
		*lst = node;
	else
	{
		temp = *lst;
		while (temp->next)
			temp = temp->next;
		temp->next = node;
	}
}
