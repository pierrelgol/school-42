/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:41:36 by pollivie          #+#    #+#             */
/*   Updated: 2023/10/03 15:41:37 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	register t_list	*itter;

	if (lst && f)
	{
		itter = lst;
		while (itter)
		{
			f(itter->content);
			itter = itter->next;
		}
	}
}
