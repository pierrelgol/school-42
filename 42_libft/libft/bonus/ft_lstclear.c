/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:41:12 by pollivie          #+#    #+#             */
/*   Updated: 2023/10/03 15:41:14 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	register t_list	*next;
	register t_list	*prev;

	if (lst && *lst && del)
	{
		next = *lst;
		while (next)
		{
			prev = next;
			next = next->next;
			if (prev)
			{
				del(prev->content);
				free(prev);
			}
		}
		*lst = NULL;
	}
}
