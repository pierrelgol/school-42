#ifndef NUM_STACK_H
#define NUM_STACK_H

#include "../lib/num_base.h"

#define STACK_DEFAULT_SIZE 16

t_stack	*stack_init(int nbr_elem);
bool	stack_push(t_stack *self, char *elem);
char   *stack_pop(t_stack *self);
char   *stack_peek(t_stack *self, int index);
void	stack_dispose(t_stack *self);

#endif

