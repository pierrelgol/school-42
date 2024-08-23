/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:31:19 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/07 13:37:03 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	*ptab;
	int	temp;

	if (tab != (void *)0 && size >= 2)
	{
		ptab = tab;
		while (ptab < &tab[--size])
		{
			temp = *ptab;
			*ptab++ = tab[size];
			tab[size] = temp;
		}
	}
}
