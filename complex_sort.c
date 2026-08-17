#include "push_swap.h"
#include "stdio.h"
void display_stack(t_list *tab);
void display_indexes(t_list *tab);

int find_number_of_digits(int n)
{
	int number_of_digits;

	number_of_digits = 0;
	while (n)
	{
		n /= 2;
		number_of_digits++;
	}
	return (number_of_digits);
}

int find_max_number(t_stack stack)
{
	int max_number;
	t_list *node;

	max_number = 0;
	node = stack.first_node;
	while (node)
	{
		if (max_number < node->number)
			max_number = node->number;
		node = node->next;
	}
	return (max_number);
}
//początek indeksacji
//bardzo nieoptymalna jest indeksacja, jak bedzie czas to przepisze to na cos lepszego
t_list	*find_node_with_first_max(t_stack stack, int max)
{
	t_list *node;

	node = stack.first_node;
	while (node)
	{
		if (node->number == max)
			return (node);
		node = node->next;
	}
	return (NULL);
}

t_list *find_node_with_prev_max(t_stack stack, int *next_max)
{
	int max_number;
	t_list *max_node;
	t_list *node;

	max_number = 0;
	max_node = NULL;
	node = stack.first_node;
	while (node)
	{
		if (node->number < *next_max && max_number < node->number)
			{
				max_number = node->number;
				max_node = node;
			}
		node = node->next;
	}
	*next_max = max_number;
	return (max_node);
}

t_list	*find_node_with_last_max(t_stack stack)
{
	t_list *node;

	node = stack.first_node;
	while (node)
	{
		if (node->index == 0)
			return (node);
		node = node->next;
	}
	return (NULL);
}

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
// koniec indeksacji

void put_to_stack_b(t_stack *stack_a, t_stack *stack_b, t_list *node_a, t_ops *ops)
{
	int rotate_ops;
	//printf("number: %d\n", node_a->number);

	rotate_ops = 0;
	while (stack_a->first_node->index != node_a->index)
	{
		ra(stack_a, ops);
		rotate_ops++;
	}
	pb(stack_a, stack_b, ops);
	while (rotate_ops)
	{
		rra(stack_a, ops);
		rotate_ops--;
	}
	// printf("display_stack a:\n");
	// display_stack(stack_a->first_node);
	// printf("display_stack b\n");
	// display_stack(stack_b->first_node);
	
}

void put_to_stack_a(t_stack *stack_a, t_stack *stack_b, t_ops *ops)
{
	// to stack_b->first_node jest brzydkie chyba, przepisac
	while (stack_b->first_node)
	{
		rrb(stack_b, ops);
		// printf("number: %d\n", stack_b->first_node->number);
		pa(stack_a, stack_b, ops);
		// printf("display_stack a:\n");
		// display_stack(stack_a->first_node);
		// printf("display_stack b\n");
		// display_stack(stack_b->first_node);
		ra(stack_a, ops);
	}
}

void complex_sort(t_stack *stack_a, t_stack *stack_b, t_ops *ops)
{
	t_list *tmpa;
	int i;
	int max_digits;

	tmpa = stack_a->first_node;
	i = 0;
	max_digits = find_number_of_digits(find_max_number(*stack_a));
	//printf("stack a numbers:\n");
	//display_stack(stack_a->first_node);
	indexate(stack_a);
	//printf("stack a indexes:\n");
	//display_indexes(stack_a->first_node);
	while (i < max_digits)
	{
		while (tmpa)
		{
			if (tmpa->index & (1 << i))
			{
				//printf("number:%i\n", tmpa->number);
				put_to_stack_b(stack_a, stack_b, tmpa, ops);
				tmpa = stack_a->first_node;
				//printf("stack a after pushing:\n");
				//display_stack(stack_a->first_node);
				//printf("stack b after pushing:\n");
				//display_stack(stack_b->first_node);
			}
			else
				tmpa = tmpa->next;
		}
		put_to_stack_a(stack_a, stack_b, ops);
		tmpa = stack_a->first_node;
		//printf("%i\n", i);
		//printf("display_stack a:\n");
		//display_stack(stack_a->first_node);
		//printf("display_stack b\n");
		//display_stack(stack_b->first_node);
		i++;
	}
}
