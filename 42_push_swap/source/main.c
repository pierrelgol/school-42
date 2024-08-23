/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:00:39 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/24 19:00:39 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_optimiser	*optimiser_init(struct s_allocator *arena, t_psw *container)
{
	t_optimiser	*self;

	self = arena->alloc(arena, sizeof(t_optimiser));
	self->a = container->a;
	self->b = container->b;
	self->rra_shift = 0;
	self->ra_shift = 0;
	self->base_score = INT_MAX;
	self->rra_score = INT_MAX;
	self->ra_score = INT_MAX;
	self->best_score = INT_MAX;
	self->best_cmd = NO_OP;
	self->part_size = 0;
	self->size = container->size;
	self->cmd = container->cmd;
	self->copy = arena->alloc(arena, (container->size + 1) * sizeof(int));
	return (self);
}

static t_istack	*istack_init(struct s_allocator *arena, int size)
{
	t_istack	*self;

	self = arena->alloc(arena, sizeof(t_istack));
	self->len = 0;
	self->mid = 0;
	self->size = size;
	self->ptr = arena->alloc(arena, size * sizeof(int));
	return (self);
}

static t_psw	*psw_init(struct s_allocator *arena, int argc, char **argv)
{
	t_psw	*self;

	self = arena->alloc(arena, sizeof(t_psw));
	if (argc == 2)
	{
		self->inputs = string_split(arena, argv[1], " ");
		self->size = split_size(self->inputs);
	}
	else
	{
		self->inputs = &argv[1];
		self->size = argc - 1;
	}
	self->a = istack_init(arena, self->size + 1);
	self->b = istack_init(arena, self->size + 1);
	self->cmd = buffer_create(arena, 16384, false);
	self->optimiser = optimiser_init(arena, self);
	return (self);
}

static void	psw_deinit(struct s_allocator *heap, struct s_allocator *arena)
{
	arena_allocator_deinit(arena);
	heap_deinit(heap);
}

int	main(int argc, char **argv)
{
	struct s_allocator	*heap;
	struct s_allocator	*arena;
	t_psw				*container;

	if (argc >= 2)
	{
		heap = heap_init();
		arena = arena_allocator_init(heap, 65536);
		container = psw_init(arena, argc, argv);
		container->heap = heap;
		container->arena = arena;
		if (psw_start(container) != OK)
		{
			psw_deinit(heap, arena);
			psw_error();
		}
		psw_deinit(heap, arena);
		return (0);
	}
	psw_error();
}
