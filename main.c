/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacpere <akacpere@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 17:09:43 by kgirczyc          #+#    #+#             */
/*   Updated: 2026/08/31 18:05:12 by akacpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	display_stack(t_doubly_list *tab)
{
	t_doubly_list	*node;

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

void	sort(t_stack *a, t_stack *b, t_ops *ops, t_flags flags)
{
	if (flags.is_simple)
		simple_sort(a, b, ops, flags.is_bench);
	else if (flags.is_medium)
		medium_sort(a, b, ops, flags.is_bench);
	else
		complex_sort(a, b, ops, flags.is_bench);
}

int	main(int argc, char **argv)
{
	t_flags		flags;
	t_stack		stack_a;
	t_stack		stack_b;
	t_metrics	metrics;

	if (argc == 1)
		return (2);
	if (!initialize_flags(argc, argv, &flags))
		return (write(2, "Error\n", 6));
	initialize_stacks(&stack_a, &stack_b);
	if (!parse(argc, argv, &stack_a))
		return (lstclear(&stack_a.first_node), write(2, "Error\n", 6), 1);
	choose_algorithm(&flags, compute_disorder(stack_a));
	if (flags.is_bench)
		if (!initialize_metrics(&metrics, flags, stack_a))
			return (write(2, "Error\n", 6), 1);
	sort(&stack_a, &stack_b, &metrics.ops, flags);
	if (flags.is_bench)
	{
		update_metrics(&metrics);
		if (!print_benchmark(metrics))
			return (write(2, "Error\n", 6), 1);
	}
	lstclear(&stack_a.first_node);
	return (0);
}
