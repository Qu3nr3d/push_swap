#include "push_swap.h"
#include "stdio.h"
void display_stack(t_list *tab);

void indexate(t_stack *stack)
{
	int max_number;
	t_list *node;
	int number_of_elements;
	
	max_number = find_max_number(*stack);
	node = find_node_with_first_max(*stack, max_number);
	number_of_elements = ft_lstsize(stack->first_node);
	node->index = number_of_elements;
	while (--number_of_elements)
	{
		if (number_of_elements == 1)
			node = find_node_with_last_max(*stack);
		else
			node = find_node_with_prev_max(*stack, &max_number);
		node->index = number_of_elements;
	}
}

void put_to_b(t_stack *a, t_stack *b, t_list *node_a, t_ops *ops, int is_bench)
{
	int rotate_ops;
	//printf("number: %d\n", node_a->number);

	rotate_ops = 0;
	while (a->first_node->index != node_a->index)
	{
		ra(a, ops, is_bench);
		rotate_ops++;
	}
	pb(a, b, ops, is_bench);
	while (rotate_ops)
	{
		rra(a, ops, is_bench);
		rotate_ops--;
	}
	// printf("display_stack a:\n");
	// display_stack(a->first_node);
	// printf("display_stack b\n");
	// display_stack(b->first_node);
	
}

void put_to_a(t_stack *a, t_stack *b, t_ops *ops, int is_bench)
{
	// to b->first_node jest brzydkie chyba, przepisac
	while (b->first_node)
	{
		rrb(b, ops, is_bench);
		// printf("number: %d\n", b->first_node->number);
		pa(a, b, ops, is_bench);
		// printf("display_stack a:\n");
		// display_stack(a->first_node);
		// printf("display_stack b\n");
		// display_stack(b->first_node);
		ra(a, ops, is_bench);
	}
}

int is_sorted(t_stack a)
{
	t_list *node;

	node = a.first_node;
	while (node->next)
	{
		if (node->number > node->next->number)
			return (0);
		node = node->next;
	}
	return (1);
}

void complex_sort(t_stack *a, t_stack *b, t_ops *ops, int is_bench)
{
	int i;
	int j;
	//int max_digits;

	i = 0;
	j = 0;
	//max_digits = find_number_of_digits(a->size);
	//printf("stack a numbers:\n");
	//display_stack(a->first_node);
	indexate(a);
	//printf("stack a indexes:\n");
	//display_indexes(a->first_node);
	while (!is_sorted(*a))
	{
		while (a->first_node && j < a->size)
		{
			if ((a->first_node->index & (1 << i)) == 0)
			{
				//printf("number:%i\n", tmpa->number);
				
				pb(a, b, ops, is_bench);
				//printf("stack a after pushing:\n");
				//display_stack(a->first_node);
				//printf("stack b after pushing:\n");
				//display_stack(b->first_node);
			}
			else
				ra(a, ops, is_bench);
			j++;
		}
		while (b->first_node)
			pa(a, b, ops, is_bench);
		j = 0;
		i++;
	}
		// put_to_a(a, b, ops, is_bench);
		// tmpa = a->first_node;
		//printf("%i\n", i);
		//printf("display_stack a:\n");
		//display_stack(a->first_node);
		//printf("display_stack b\n");
		//display_stack(b->first_node);
		// i++;
}

