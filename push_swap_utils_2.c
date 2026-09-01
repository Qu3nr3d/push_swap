/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacpere <akacpere@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 16:44:41 by kgirczyc          #+#    #+#             */
/*   Updated: 2026/09/01 13:26:51 by akacpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->first_node = NULL;
	stack_a->last_node = NULL;
	stack_a->size = 0;
	stack_b->first_node = NULL;
	stack_b->last_node = NULL;
	stack_b->size = 0;
}

t_ops	init_ops(void)
{
	t_ops	ops;

	ops.use_pa = 0;
	ops.use_pb = 0;
	ops.use_sa = 0;
	ops.use_sb = 0;
	ops.use_ss = 0;
	ops.use_ra = 0;
	ops.use_rb = 0;
	ops.use_rr = 0;
	ops.use_rra = 0;
	ops.use_rrb = 0;
	ops.use_rrr = 0;
	return (ops);
}

bool	is_sorted(t_stack a)
{
	t_doubly_list	*node;

	node = a.first_node;
	while (node->next)
	{
		if (node->number > node->next->number)
			return (false);
		node = node->next;
	}
	return (true);
}

int	find_max_number(t_stack stack)
{
	int				max_number;
	t_doubly_list	*node;

	max_number = INT_MIN;
	node = stack.first_node;
	while (node)
	{
		if (max_number < node->number)
			max_number = node->number;
		node = node->next;
	}
	return (max_number);
}

int	find_min_number(t_stack stack)
{
	int				min_number;
	t_doubly_list	*node;

	min_number = INT_MAX;
	node = stack.first_node;
	while (node)
	{
		if (min_number > node->number)
			min_number = node->number;
		node = node->next;
	}
	return (min_number);
}
