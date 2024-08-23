/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:29:43 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/14 15:29:44 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "clib.h"
# include <limits.h>
# define OK 1
# define ERR 0

typedef enum e_cmd
{
	NO_OP = 0,
	SA = 1,
	PA,
	RA,
	RRA,
	SB,
	PB,
	RB,
	RRB,
	SS,
	RR,
	RRR,
}						t_cmd;

typedef enum e_id
{
	ID_STACK_A,
	ID_STACK_B,
}						t_id;

typedef struct s_vec4
{
	int					a;
	int					b;
	int					c;
	int					d;

}						t_vec4;

typedef struct s_istack
{
	int					*ptr;
	int					len;
	int					mid;
	int					size;

}						t_istack;

typedef struct s_optimiser
{
	t_istack			*a;
	t_istack			*b;
	int					*copy;
	int					size;
	t_buffer			*cmd;
	int					base_score;
	int					rra_score;
	int					ra_score;
	int					rra_shift;
	int					ra_shift;
	int					best_score;
	int					best_shift;
	t_cmd				best_cmd;
	int					part_size;
	int					depth;

}						t_optimiser;

typedef struct s_psw
{
	struct s_allocator	*heap;
	struct s_allocator	*arena;
	t_optimiser			*optimiser;
	t_buffer			*cmd;
	t_istack			*a;
	t_istack			*b;
	int					size;
	char				**inputs;

}						t_psw;

// ************************************************************************** //
//                                     psw_command                            //
// ************************************************************************** //
void					psw_push_a(t_psw *self);
void					psw_push_b(t_psw *self);
void					psw_swap(t_psw *self, t_id select);
void					psw_rotate(t_psw *self, t_id select);
void					psw_reverse_rotate(t_psw *self, t_id select);

// ************************************************************************** //
//                                     psw_command_utils1                     //
// ************************************************************************** //

void					psw_rotate_until_top(t_psw *container, t_id select,
							int num);
void					psw_reverse_rotate_until_top(t_psw *container,
							t_id select, int num);
void					psw_nrotate(t_psw *container, t_id select, int n);
void					psw_nreverse_rotate(t_psw *container, t_id select,
							int n);

// ************************************************************************** //
//                                     psw_error                              //
// ************************************************************************** //

void					psw_error(void);

// ************************************************************************** //
//                                     psw_helpers                            //
// ************************************************************************** //

int						split_size(char **split);
int						square_root(int n);

// ************************************************************************** //
//                                     psw_optimizer                          //
// ************************************************************************** //

void					psw_optimize(t_psw *container, t_optimiser *optimizer);

// ************************************************************************** //
//                                     psw_optimizer_utils1                   //
// ************************************************************************** //

int						psw_find_partition_size(int input_size);
int						psw_find_simulation_depth(int input_size);
bool					psw_count_under_threshold(t_optimiser *optimizer);
void					psw_maybe_update_score(t_optimiser *optimizer,
							t_cmd cmd);

// ************************************************************************** //
//                                     psw_optimizer_utils2                   //
// ************************************************************************** //

int						psw_get_count(t_buffer *buffer);
int						psw_get_decount(t_buffer *buffer);
int						psw_get_instruction_count(t_optimiser *optimizer);
void					psw_optimize_instructions(char *buffer, int size);

// ************************************************************************** //
//                                     psw_parser                             //
// ************************************************************************** //

bool					psw_parse(t_psw *container, t_istack *stack,
							char **input, int size);

// ************************************************************************** //
//                                     psw_process                            //
// ************************************************************************** //

void					psw_print(t_psw *self);

// ************************************************************************** //
//                                     psw_process                            //
// ************************************************************************** //

bool					psw_start(t_psw *container);

// ************************************************************************** //
//                                     psw_sort1                              //
// ************************************************************************** //

void					psw_sort2(t_psw *container, t_istack *a);
void					psw_sort3(t_psw *container, t_istack *a);
void					psw_sort4(t_psw *container, t_istack *a);
void					psw_sort5(t_psw *container, t_istack *a);

// ************************************************************************** //
//                                     psw_sort2                              //
// ************************************************************************** //

void					psw_partition_sort(t_psw *container, t_istack *a,
							t_istack *b, int psize);

// ************************************************************************** //
//                                     psw_sort_utils1                        //
// ************************************************************************** //

bool					psw_sorted(int *array, int len);
int						psw_get_min(int *array, int len);
int						psw_get_max(int *array, int len);
int						psw_get_next_min(int *array, int len, int min);
int						psw_get_next_max(int *array, int len, int max);

// ************************************************************************** //
//                                     psw_sort_utils2                        //
// ************************************************************************** //

int						psw_index_of(int *array, int len, int value);
int						psw_index_of_next_min(int *array, int len, int min);
void					psw_move_min_top(t_psw *container, t_id select);
void					psw_move_max_top(t_psw *container, t_id select);

// ************************************************************************** //

#endif
