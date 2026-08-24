#include "push_swap.h"
#include "stdio.h"

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

int is_sorted(t_stack a)
{
	t_list *node;

	node = a.first_node;
	//printf("display stack in is_sorted:\n");
	//display_stack(a.first_node);
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
	int max_digits;
	int size;

	i = 0;
	j = 0;
	max_digits = find_number_of_digits(a->size);
	//printf("stack a numbers:\n");
	//display_stack(a->first_node);
	indexate(a);
	//printf("stack a indexes:\n");
	//display_index(a->first_node);
	//display_index_in_binary(a->first_node);
	size = a->size;
	while (i < max_digits)
	{
		while (a->first_node && j < size)
		{
			if ((a->first_node->index & (1 << i)) == 0)
			{
				//printf("number:%s\n", index_in_binary(a->first_node->index));
				
				pb(a, b, ops, is_bench);
				//printf("stack a after pushing to b:\n");
				//display_index(a->first_node);
				//display_index_in_binary(a->first_node);
				//printf("stack b after pushing to b:\n");
				//display_index(b->first_node);
				//display_index_in_binary(b->first_node);
			}
			else
			{
				//printf("number:%s\n", index_in_binary(a->first_node->index));
				ra(a, ops, is_bench);
				//printf("stack a after rotation:\n");
				//display_index(a->first_node);
				//display_index_in_binary(a->first_node);
			}
			j++;
			//printf("size: %d\n", size);
			//printf("j: %d\n", j);
		}
		while (b->first_node)
		{
			pa(a, b, ops, is_bench);
		}
		//printf("stack a after one sort:\n");
		//display_index(a->first_node);
		//display_index_in_binary(a->first_node);
		j = 0;
		i++;
		//printf("display stack in sort:\n");
		//display_stack(a->first_node);
	}
}