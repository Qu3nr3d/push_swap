#include "push_swap.h"
#include <stdarg.h>
#include <stdio.h>


void display_stack(t_list *tab)
{
	t_list *node;

	node = tab;
	while (node)
	{
		printf("| ");
		printf("%d", node->number);
		printf(" |");
		node = node->next;
		printf("\n");
	}
	printf("\n");
}

void display_index(t_list *tab)
{
	t_list *node;

	node = tab;
	while (node)
	{
		printf("| ");
		printf("%d", node->index);
		printf(" |");
		node = node->next;
		printf("\n");
	}
	printf("\n");
}

void sort(t_stack *a, t_stack *b, t_ops *ops, t_flags flags)
{
	if (flags.is_simple)
		simple_sort(a, b, ops, flags.is_bench);
	else if (flags.is_medium)
		medium_sort(a, b, ops, flags.is_bench);
	else
		complex_sort(a, b, ops, flags.is_bench);
}

void free_stacks(t_stack *a, t_stack *b)
{
	ft_lstclear(&a->first_node);
	a->last_node = NULL;
	ft_lstclear(&b->first_node);
	b->last_node = NULL;
}

// robienie free jak będzie error (free przepisac)
// algorytm mój przepisac aby był okej
// maina przepisać
int	main(int argc, char **argv)
{
	t_flags	flags;
	t_stack stack_a;
	t_stack stack_b;
	t_metrics metrics;
	float disorder;
	
	if (argc == 1)
		return (2);
	if(!initialize_flags(argc, argv, &flags))
		return(write(2, "Error\n", 6));
	initialize_stacks(&stack_a, &stack_b);
	if (!parse(argc, argv, &stack_a))
		return (write(2, "Error\n", 6), 1);
	disorder = compute_disorder(stack_a);
	choose_algorithm(&flags, disorder);
	if (!initialize_metrics(&metrics, flags, stack_a))
		return (write(2, "Error\n", 6), 1);
	sort(&stack_a, &stack_b, &metrics.ops, flags);
	if (flags.is_bench)
	{
		update_metrics(&metrics);
		if (!print_benchmark(metrics))
			return (write(2, "Error\n", 6), 1);
	}
	display_stack(stack_a.first_node);
	display_index(stack_a.first_node);
	free_stacks(&stack_a, &stack_b);
	return (0);
}
