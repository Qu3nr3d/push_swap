#include "push_swap.h"

void	rra(t_stack *stack, int *counter)
{
	t_list	*last;

	if (stack->size < 2)
		return;
	last = stack->last_node;
	stack->last_node = last->prev;
	stack->last_node->next = NULL;
	last->prev = NULL;
	last->next = stack->first_node;
	stack->first_node->prev = last;
	stack->first_node = last;
    (*counter)++;
}

void	rrb(t_stack *stack, int *counter)
{
	t_list	*last;

	if (stack->size < 2)
		return;
	last = stack->last_node;
	stack->last_node = last->prev;
	stack->last_node->next = NULL;
	last->prev = NULL;
	last->next = stack->first_node;
	stack->first_node->prev = last;
	stack->first_node = last;
    (*counter)++;
}

void rrr(t_stack *stack_a, t_stack *stack_b, int *counter)
{
	rra(stack_a, counter);
	rrb(stack_b, counter);
}
