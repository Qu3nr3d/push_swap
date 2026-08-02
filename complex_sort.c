#include "push_swap.h"
#include "stdio.h"
void display_stack(t_list *tab);

// nie wiem czemu wskazuje na rzeczy ze stack b
void put_to_stack_b(t_stack *stack_a, t_stack *stack_b, t_list *node_a)
{
	printf("number: %d\n", node_a->number);
	while (node_a->prev)
	{
		ra(&stack_a->first_node, &stack_a->last_node);
		if (node_a->prev)
			node_a = node_a->prev;
	}
	pb(&stack_a->first_node, &stack_b->first_node);
	printf("display_stack a:\n");
	display_stack(stack_a->first_node);
	printf("display_stack b\n");
	display_stack(stack_b->first_node);
}

void sort(t_stack *stack_a, t_stack *stack_b)
{
	t_list *tmpa;

	tmpa = stack_a->first_node;
	while (tmpa)
	{
		if (tmpa->number & 1)
		{
			put_to_stack_b(stack_a, stack_b, tmpa);
			tmpa = stack_a->first_node;
		}
		else
			tmpa = tmpa->next;
	}
}