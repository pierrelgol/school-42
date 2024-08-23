/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bissenma <bissenma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:53:08 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/24 12:15:01 by bissenma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../lib/num_base.h"
#include "../lib/num_print.h"
#include "../lib/num_debug.h"


void	debug_file(t_file *file)
{
	print_putstr("file->fd = ");
	print_putnbr(file->fd);
	print_putstr("\n");
	print_putstr("file->is_open = ");
	print_putnbr(file->is_open);
	print_putstr("\n");
	print_putstr("file->status = ");
	print_putnbr(file->status);
	print_putstr("\n");
	print_putstr("file->byte_read = ");
	print_putnbr(file->byte_read);
	print_putstr("\n");
	print_putstr("file->buffer = ");
	print_putstr(file->buffer);
	print_putstr("\n");

}
void	debug_stack(t_stack *stack)
{
	print_putstr("stack->capacity = ");
	print_putnbr(stack->capacity);
	print_putstr("\n");
	print_putstr("stack->count = ");
	print_putnbr(stack->count);
	print_putstr("\n");
	print_putstr("stack->status = ");
	print_putnbr(stack->status);
	print_putstr("\n");
	print_putstr("stack->elems = ");
	print_putstr((char*)stack->elems);
	print_putstr("\n");
}

void	debug_entry(t_entry *entry)
{
	/*
		@WIP :

	*/

	// print_putstr("entry->lexer_raw = ");
	// print_putstr(entry->lexer_raw);
	// print_putstr("\n");
	// print_putstr("entry->col = ");
	// print_putnbr(entry->col);
	// print_putstr("\n");
	// print_putstr("entry->row = ");
	// print_putnbr(entry->row);
	// print_putstr("\n");
}

void	debug_ast(t_ast *ast)
{
	print_putstr("ast->dict_rows = ");
	print_putnbr(ast->dict_rows);
	print_putstr("\n");
	print_putstr("ast->disct_cols = ");
	print_putnbr(ast->disct_cols);
	print_putstr("\n");
	// print_putstr("ast->row = ");
	// print_putnbr(ast->row);
	// print_putstr("\n");
}

void	debug_slice(t_slice *slice)
{
	int i;

	i = 0;
	print_putstr("slice->status = ");
	print_putnbr(slice->status);
	print_putstr("\n");
	print_putstr("slice->chr_len = ");
	print_putnbr(slice->chr_len);
	print_putstr("\n");
	print_putstr("slice->chr_slice = ");
	print_putstr(slice->chr_slice);
	print_putstr("\n");
	print_putnbr(slice->dec_len);
	while (i < slice->dec_len)
	{
		print_putnbr(slice->dec_slice[i++]);
		print_putstr(", ");
	}
	print_putstr("\n");
}
