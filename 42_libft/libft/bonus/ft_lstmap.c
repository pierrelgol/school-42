/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:42:01 by pollivie          #+#    #+#             */
/*   Updated: 2023/10/03 15:42:02 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*modified_head;
	t_list	*modified;

	if (!(lst && f && del))
		return (NULL);
	modified = ft_lstnew(f(lst->content));
	if (modified == NULL)
		return (NULL);
	lst = lst->next;
	modified_head = modified;
	while (lst)
	{
		modified->next = ft_lstnew(f(lst->content));
		if (modified->next == NULL)
		{
			ft_lstclear(&modified, del);
			return (NULL);
		}
		modified = modified->next;
		lst = lst->next;
	}
	modified->next = NULL;
	return (modified_head);
}
