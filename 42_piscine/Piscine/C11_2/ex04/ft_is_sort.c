/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:33:07 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/25 09:33:08 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	is_ascend;
	int	is_descend;
	int	i;

	i = 0;
	is_ascend = 1;
	is_descend = 1;
	if (length <= 1)
		return (1);
	while (i < length - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) > 0)
			is_ascend = 0;
		++i;
	}
	i = 0;
	while (i < length - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) < 0)
			is_descend = 0;
		++i;
	}
	if (is_ascend == 1 || is_descend == 1)
		return (1);
	return (0);
}
