/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_optimizer_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 11:25:28 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/25 11:25:36 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	psw_get_count(t_buffer *buffer)
{
	return (buffer->w);
}

int	psw_get_decount(t_buffer *buffer)
{
	t_cmd	cmd1;
	t_cmd	cmd2;
	int		count;
	int		index;
	int		size;

	index = 1;
	count = 0;
	size = (int)buffer->w;
	while (index < size)
	{
		cmd1 = buffer->buffer[index - 1];
		cmd2 = buffer->buffer[index];
		if ((cmd1 == SA && cmd2 == SB) || (cmd1 == SB && cmd2 == SA))
			count++;
		else if ((cmd1 == RA && cmd2 == RB) || (cmd1 == RB && cmd2 == RA))
			count++;
		else if ((cmd1 == RRA && cmd2 == RRB) || (cmd1 == RRB && cmd2 == RRA))
			count++;
		index++;
	}
	return (count);
}

void	psw_optimize_instructions(char *buffer, int size)
{
	int		i;
	t_cmd	cmd1;
	t_cmd	cmd2;

	i = 0;
	while (++i < size)
	{
		cmd1 = buffer[i - 1];
		cmd2 = buffer[i];
		if ((cmd1 == SA && cmd2 == SB) || (cmd1 == SB && cmd2 == SA))
		{
			buffer[i - 1] = SS;
			buffer[i] = NO_OP;
		}
		else if ((cmd1 == RA && cmd2 == RB) || (cmd1 == RB && cmd2 == RA))
		{
			buffer[i - 1] = RR;
			buffer[i] = NO_OP;
		}
		else if ((cmd1 == RRA && cmd2 == RRB) || (cmd1 == RRB && cmd2 == RRA))
		{
			buffer[i - 1] = RRR;
			buffer[i] = NO_OP;
		}
	}
}
