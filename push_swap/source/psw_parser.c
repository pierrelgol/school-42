/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 11:10:40 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/25 11:10:40 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <limits.h>

static long	psw_to_long(char *input)
{
	long	result;
	long	sign;

	result = 0;
	sign = 1;
	while (char_is_spaces(*input))
		++input;
	if (*input == '-')
	{
		++input;
		sign = -1;
	}
	while (char_is_digit(*input))
		result = (*input++ - '0') + result * 10;
	return (result * sign);
}

static bool	psw_syntax_check(char *input)
{
	int	digit_count;
	int	ch;

	digit_count = 0;
	while (*input)
	{
		ch = *input++;
		if (char_is_digit(ch))
			digit_count++;
		else if (ch != '-')
			return (0);
	}
	return (digit_count >= 1);
}

static bool	psw_range_check(long num)
{
	return (num >= INT_MIN && num <= INT_MAX);
}

static bool	psw_unique_check(t_table *table, char *input)
{
	return (table_entry_get(table, input) == 0);
}

bool	psw_parse(t_psw *container, t_istack *stack, char **input, int size)
{
	t_table	*table;
	long	num;
	int		i;

	i = 0;
	table = table_create(container->heap);
	while (i < size)
	{
		num = psw_to_long(input[i]);
		if (psw_syntax_check(input[i]) != OK)
			break ;
		if (psw_range_check(num) != OK)
			break ;
		if (psw_unique_check(table, input[i]) != OK)
			break ;
		stack->ptr[i] = (int)num;
		stack->len++;
		table_entry_set(table, input[i], num);
		++i;
	}
	table_destroy(table);
	return (i == size);
}
