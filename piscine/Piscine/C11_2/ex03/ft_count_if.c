/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:32:34 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/25 09:32:35 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char *))
{
	int	count;
	int	i;

	if (!tab || !f)
		return (0);
	i = 0;
	count = 0;
	while (i < length)
	{
		if (f(tab[i]) != 0)
			++count;
		++i;
	}
	return (count);
}
