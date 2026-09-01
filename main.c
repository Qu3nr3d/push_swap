/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgirczyc <kgirczyc@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 17:09:43 by kgirczyc          #+#    #+#             */
/*   Updated: 2026/09/01 17:45:26 by kgirczyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	small_sort(t_stack *a, t_stack *b, t_ops *ops, int is_bench)
{
	int	max_number;
	int	min_number;

	if (is_sorted(*a))
		return ;
	min_number = 0;
	while (a->size > 3)
	{
		min_number = find_min_number(*a);
		while (a->first_node->number != min_number)
			ra(a, ops, is_bench);
		pb(a, b, ops, is_bench);
	}
	max_number = (find_max_number(*a));
	if (a->first_node->number == max_number)
		ra(a, ops, is_bench);
	if (a->first_node->next->number == max_number)
		rra(a, ops, is_bench);
	if (a->first_node->number > a->first_node->next->number)
		sa(a, ops, is_bench);
	while (b->first_node != NULL)
		pa(a, b, ops, is_bench);
}

static void	sort(t_stack *a, t_stack *b, t_ops *ops, t_flags flags)
{
	if (a->size <= 5)
		small_sort(a, b, ops, flags.is_bench);
	else if (flags.is_simple)
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
	if (!init_flags(argc, argv, &flags))
		return (write(2, "Error\n", 6));
	init_stacks(&stack_a, &stack_b);
	if (!parse(argc, argv, &stack_a))
		return (lstclear(&stack_a.first_node), write(2, "Error\n", 6), 1);
	choose_algorithm(&flags, compute_disorder(stack_a));
	if (flags.is_bench)
		if (!init_metrics(&metrics, flags, stack_a))
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
