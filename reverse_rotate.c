#include "push_swap.h"

//zabezpieczyc NULL
void	rra(t_stack *stack)
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
}

void	rrb(t_stack *stack)
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
}

void rrr(t_stack *stack)
{
	rra(stack);
	rrb(stack);
}
