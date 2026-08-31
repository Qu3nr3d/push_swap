/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacpere <akacpere@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 17:53:17 by kgirczyc          #+#    #+#             */
/*   Updated: 2026/08/31 15:37:50 by akacpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_pos(t_stack *a)
{
	t_doubly_list	*node;
	int		min;
	int		pos;
	int		min_pos;

	node = a->first_node;
	min = node->number;
	pos = 0;
	min_pos = 0;
	while (node)
	{
		if (node->number < min)
		{
			min = node->number;
			min_pos = pos;
		}
		node = node->next;
		pos++;
	}
	return (min_pos);
}

static void	push_min(t_stack *a, t_stack *b, t_ops *ops, int is_bench)
{
	int	pos;

	pos = find_min_pos(a);
	if (pos <= a->size / 2)
	{
		while (pos > 0)
		{
			ra(a, ops, is_bench);
			pos--;
		}
	}
	else
	{
		pos = a->size - pos;
		while (pos-- > 0)
			rra(a, ops, is_bench);
	}
	pb(a, b, ops, is_bench);
}

void	simple_sort(t_stack *a, t_stack *b, t_ops *ops, int is_bench)
{
	if (a->size <= 1 || is_sorted(*a))
		return ;
	while (a->size > 0)
		push_min(a, b, ops, is_bench);
	while (b->size > 0)
		pa(a, b, ops, is_bench);
}
