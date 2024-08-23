/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:44:34 by pollivie          #+#    #+#             */
/*   Updated: 2023/10/17 13:44:35 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

float	ft_factf(float n)
{
	float	result;

	if (n <= 0)
		return (1);
	result = n;
	while (--n > 1)
		result *= n;
	return (result);
}
