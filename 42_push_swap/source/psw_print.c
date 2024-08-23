/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 13:45:11 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/25 13:45:11 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	psw_puts(char *str)
{
	uint64_t	len;

	len = string_length(str);
	write(1, str, len);
}

void	print_cmd(t_cmd cmd)
{
	if (cmd == NO_OP)
		return ;
	if (cmd == PA)
		psw_puts("pa\n");
	if (cmd == SA)
		psw_puts("sa\n");
	if (cmd == RA)
		psw_puts("ra\n");
	if (cmd == RRA)
		psw_puts("rra\n");
	if (cmd == PB)
		psw_puts("pb\n");
	if (cmd == SB)
		psw_puts("sb\n");
	if (cmd == RB)
		psw_puts("rb\n");
	if (cmd == RRB)
		psw_puts("rrb\n");
	if (cmd == SS)
		psw_puts("ss\n");
	if (cmd == RR)
		psw_puts("rr\n");
	if (cmd == RRR)
		psw_puts("rrr\n");
}

void	psw_print(t_psw *self)
{
	t_buffer	*cmd_buffer;
	t_cmd		cmd;

	cmd_buffer = self->cmd;
	psw_optimize_instructions(cmd_buffer->buffer, cmd_buffer->w);
	while (buffer_unread_count(cmd_buffer))
	{
		cmd = buffer_getch(cmd_buffer);
		print_cmd(cmd);
	}
}
