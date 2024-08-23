/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:41:49 by pollivie          #+#    #+#             */
/*   Updated: 2023/10/03 15:41:50 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	register t_list	*itter;

	if (lst)
	{
		itter = lst;
		while (itter->next)
		{
			itter = itter->next;
		}
		return (itter);
	}
	return (NULL);
}
