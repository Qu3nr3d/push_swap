#include "checker.h"

void	initialize_stacks(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->first_node = NULL;
	stack_a->last_node = NULL;
	stack_a->size = 0;
	stack_b->first_node = NULL;
	stack_b->last_node = NULL;
	stack_b->size = 0;
}