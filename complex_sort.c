/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacpere <akacpere@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 20:56:40 by akacpere          #+#    #+#             */
/*   Updated: 2026/08/31 15:38:51 by akacpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexate(t_stack *stack)
{
	int		max_number;
	t_doubly_list	*node;
	int		number_of_elements;

	max_number = find_max_number(*stack);
	node = find_node_with_first_max(*stack, max_number);
	number_of_elements = lstsize(stack->first_node);
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

void	complex_sort(t_stack *a, t_stack *b, t_ops *ops, int is_bench)
{
	int	i;
	int	j;
	int	max_digits;
	int	size;

	i = 0;
	j = 0;
	max_digits = find_number_of_digits(a->size);
	indexate(a);
	size = a->size;
	while (!is_sorted(*a) && (i < max_digits))
	{
		while (a->first_node && j++ < size)
		{
			if ((a->first_node->index & (1 << i)) == 0)
				pb(a, b, ops, is_bench);
			else
				ra(a, ops, is_bench);
		}
		while (b->first_node)
			pa(a, b, ops, is_bench);
		j = 0;
		i++;
	}
	return ;
}
