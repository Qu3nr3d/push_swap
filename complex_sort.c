#include "push_swap.h"
#include "stdio.h"
void display_stack(t_list *tab);

void put_to_stack_b(t_stack *stack_a, t_stack *stack_b, t_list *node_a)
{
	int rotate_operations;
	//printf("number: %d\n", node_a->number);
	rotate_operations = 0;
	while (stack_a->first_node->number != node_a->number)
	{
		ra(&stack_a->first_node, &stack_a->last_node);
		rotate_operations++;
	}
	pb(&stack_b->first_node, &stack_a->first_node, &stack_b->last_node, &stack_a->last_node);
	while (rotate_operations)
	{
		rra(&stack_a->first_node, &stack_a->last_node);
		rotate_operations--;
	}
	// printf("display_stack a:\n");
	// display_stack(stack_a->first_node);
	// printf("display_stack b\n");
	// display_stack(stack_b->first_node);
	
}

void sort(t_stack *stack_a, t_stack *stack_b)
{
	t_list *tmpa;
	int i;

	tmpa = stack_a->first_node;
	i = 0;
	while (i < 5)
	{
		while (tmpa)
		{
			if (tmpa->number & (1 << i))
			{
				printf("number:%i\n", tmpa->number);
				put_to_stack_b(stack_a, stack_b, tmpa);
				tmpa = stack_a->first_node;
				printf("stack a after pushing:\n");
				display_stack(stack_a->first_node);
				printf("stack b after pushing:\n");
				display_stack(stack_b->first_node);
			}
			else
				tmpa = tmpa->next;
		}
		put_to_stack_a(stack_a, stack_b);
		tmpa = stack_a->first_node;
		printf("%i\n", i);
		printf("display_stack a:\n");
		display_stack(stack_a->first_node);
		printf("display_stack b\n");
		display_stack(stack_b->first_node);
		i++;
	}
}

void put_to_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	// to stack_b->first_node jest brzydkie chyba, przepisac
	while (stack_b->first_node)
	{
		rrb(&stack_b->first_node, &stack_b->last_node);
		// printf("number: %d\n", stack_b->first_node->number);
		pa(&stack_a->first_node, &stack_b->first_node, &stack_a->last_node, &stack_b->last_node);
		// printf("display_stack a:\n");
		// display_stack(stack_a->first_node);
		// printf("display_stack b\n");
		// display_stack(stack_b->first_node);
		ra(&stack_a->first_node, &stack_a->last_node);
	}
}