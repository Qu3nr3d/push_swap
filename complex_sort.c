#include "push_swap.h"

void put_to_stack_b(t_stack *stack_a, t_stack *stack_b, t_list *node_a)
{
	while(node_a->prev)
	{
		rra(&stack_a->first_node, &stack_a->last_node);
		node_a = node_a->prev;
	}
	pa(&stack_a->first_node, &stack_b->first_node);
}

void sort(t_stack *stack_a, t_stack *stack_b)
{
	t_list *tmpa;

	tmpa = stack_a->first_node;
	stack_b = (void *)stack_b;
	while (tmpa)
	{
		if (tmpa->number & 1)
			put_to_stack_b(stack_a, stack_b, tmpa);
		tmpa = tmpa->next;
	}
}