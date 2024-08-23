/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_sort_utils1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 11:24:51 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/25 11:24:51 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <limits.h>

bool	psw_sorted(int *array, int len)
{
	int	index;

	if (!array || len <= 0)
		return (false);
	index = 1;
	while (index < len)
	{
		if (array[index - 1] > array[index])
			return (false);
		++index;
	}
	return (true);
}

int	psw_get_min(int *array, int len)
{
	int	index;
	int	min;

	if (!array || len == 0)
		return (0);
	index = 0;
	min = array[0];
	while (index < len)
	{
		if (array[index] < min)
			min = array[index];
		++index;
	}
	return (min);
}

int	psw_get_max(int *array, int len)
{
	int	index;
	int	max;

	if (!array || len == 0)
		return (0);
	index = 0;
	max = array[0];
	while (index < len)
	{
		if (array[index] > max)
			max = array[index];
		++index;
	}
	return (max);
}

int	psw_get_next_min(int *array, int len, int min)
{
	int	index;
	int	nmin;

	if (!array || len == 0)
		return (0);
	index = 0;
	nmin = INT_MAX;
	while (index < len)
	{
		if (array[index] > min && array[index] < nmin)
			nmin = array[index];
		++index;
	}
	return (nmin);
}

int	psw_get_next_max(int *array, int len, int max)
{
	int	index;
	int	nmax;

	if (!array || len == 0)
		return (0);
	index = 0;
	nmax = INT_MIN;
	while (index < len)
	{
		if (array[index] < max && array[index] > nmax)
			nmax = array[index];
		++index;
	}
	return (nmax);
}
