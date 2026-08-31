/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacpere <akacpere@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 17:54:14 by kgirczyc          #+#    #+#             */
/*   Updated: 2026/08/31 15:38:11 by akacpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_extreme_pos(const t_stack *stack, int ascending)
{
	t_doubly_list	*node;
	int		extreme;
	int		extreme_pos;
	int		pos;

	node = stack->first_node;
	extreme = node->number;
	extreme_pos = 0;
	pos = 0;
	while (node)
	{
		if ((ascending && node->number > extreme)
			|| (!ascending && node->number < extreme))
		{
			extreme = node->number;
			extreme_pos = pos;
		}
		node = node->next;
		pos++;
	}
	return (extreme_pos);
}

void	sort_block(t_medium *m, int size, int ascending)
{
	int	i;
	int	pos;

	i = 0;
	while (i++ < size)
		pb(m->a, m->b, m->ops, m->is_bench);
	while (m->b->size > 0)
	{
		pos = find_extreme_pos(m->b, ascending);
		if (pos <= m->b->size / 2)
			while (pos-- > 0)
				rb(m->b, m->ops, m->is_bench);
		else
		{
			pos = m->b->size - pos;
			while (pos-- > 0)
				rrb(m->b, m->ops, m->is_bench);
		}
		pa(m->a, m->b, m->ops, m->is_bench);
	}
	i = 0;
	while (i++ < size)
		ra(m->a, m->ops, m->is_bench);
}

static void	merge_values(t_medium *m, t_merge *merge)
{
	while (merge->left > 0 && merge->right > 0)
	{
		if ((merge->ascending
				&& m->a->first_node->number < m->b->first_node->number)
			|| (!merge->ascending
				&& m->a->first_node->number > m->b->first_node->number))
			merge->right--;
		else
		{
			pa(m->a, m->b, m->ops, m->is_bench);
			merge->left--;
		}
		ra(m->a, m->ops, m->is_bench);
	}
	while (merge->right-- > 0)
		ra(m->a, m->ops, m->is_bench);
	while (merge->left-- > 0)
	{
		pa(m->a, m->b, m->ops, m->is_bench);
		ra(m->a, m->ops, m->is_bench);
	}
}

void	merge_pass(t_medium *m, int total, int size, int level)
{
	t_merge	merge;
	t_pass	p;

	p.processed = 0;
	p.pair = 0;
	while (p.processed < total)
	{
		p.right_size = size;
		if (p.right_size > total - p.processed - size)
			p.right_size = total - p.processed - size;
		merge.left = size;
		merge.right = p.right_size;
		merge.ascending = get_orientation(p.pair, level);
		p.i = 0;
		while (p.i++ < size)
			pb(m->a, m->b, m->ops, m->is_bench);
		merge_values(m, &merge);
		p.processed += size + p.right_size;
		p.pair++;
	}
}
