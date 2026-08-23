/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgirczyc <kgirczyc@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 17:25:35 by kgirczyc          #+#    #+#             */
/*   Updated: 2026/08/23 18:12:43 by kgirczyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_block_size(int size)
{
	int	root;
	int	chunks;

	if (size <= 0)
		return (0);
	root = 1;
	while (root + 1 <= size / (root + 1))
		root++;
	chunks = 1;
	while (chunks * 2 <= root)
		chunks *= 2;
	if (size % chunks == 0)
		return (size / chunks);
	return (size / chunks + 1);
}

static int	get_orientation(int index, int level)
{
	int	ones;

	ones = 0;
	while (index > 0)
	{
		ones += index & 1;
		index >>= 1;
	}
	if ((level - ones) % 2 == 0)
		return (1);
	return (0);
}

static int	find_extreme_pos(const t_stack *stack, int ascending)
{
	t_list	*node;
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

static void	move_extreme_top_b(t_stack *b, int ascending,
		t_ops *ops, int is_bench)
{
	int	pos;
	int	steps;

	pos = find_extreme_pos(b, ascending);
	if (pos <= b->size / 2)
	{
		while (pos-- > 0)
			rb(b, ops, is_bench);
	}
	else
	{
		steps = b->size - pos;
		while (steps-- > 0)
			rrb(b, ops, is_bench);
	}
}

static void	sort_block(t_stack *a, t_stack *b, int *ints, t_ops *ops)
{
	int	i;

	i = 0;
	while (i++ < ints[0])
		pb(a, b, ops, ints[2]);
	while (b->size > 0)
	{
		move_extreme_top_b(b, ints[1], ops, ints[2]);
		pa(a, b, ops, ints[2]);
	}
	i = 0;
	while (i++ < ints[0])
		ra(a, ops, ints[2]);
}

static void	merge_values(t_stack **stacks, t_merge *merge,
					t_ops *ops, int is_bench)
{
	while (merge->left > 0 && merge->right > 0)
	{
		if ((merge->ascending
				&& stacks[0]->first_node->number < stacks[1]->first_node->number)
			|| (!merge->ascending
				&& stacks[0]->first_node->number > stacks[1]->first_node->number))
		{
			ra(stacks[0], ops, is_bench);
			merge->right--;
		}
		else
		{
			pa(stacks[0], stacks[1], ops, is_bench);
			ra(stacks[0], ops, is_bench);
			merge->left--;
		}
	}
	while (merge->right-- > 0)
		ra(stacks[0], ops, is_bench);
	while (merge->left-- > 0)
	{
		pa(stacks[0], stacks[1], ops, is_bench);
		ra(stacks[0], ops, is_bench);
	}
}

static void	merge_pass(t_stack *a, t_stack *b, int *ints, t_ops *ops)
{
	t_merge	merge;
	int		processed;
	int		pair;
	int		right_size;
	int		i;
	t_stack stacks;

	stacks = [a, b];
	processed = 0;
	pair = 0;
	while (processed < ints[0])
	{
		right_size = ints[1];
		if (right_size > ints[0] - processed - ints[1])
			right_size = ints[0] - processed - ints[1];
		merge.left = ints[1];
		merge.right = right_size;
		merge.ascending = get_orientation(pair, ints[2]);
		i = 0;
		while (i++ < ints[1])
			pb(a, b, ops, ints[3]);
		merge_values(&stacks, &merge, ops, ints[3]);
		processed += ints[1] + right_size;
		pair++;
	}
}

static void	merge_all(t_stack *a, t_stack *b, int *ints,
		t_ops *ops)
{
	int	size;
	int	level;

	size = ints[1];
	level = ints[2] - 1;
	while (size < ints[0])
	{
		merge_pass(a, b, {total, size, level, ints[3]}, ops);
		size *= 2;
		level--;
	}
}

void	medium_sort(t_stack *a, t_stack *b, t_ops *ops, int is_bench)
{
	int	remaining;
	int	current;
	int	blocks;
	int	depth;
	int	index;
	int ints[4];
	int sort[3];

	ints = [a->size, get_block_size(a->size), depth, is_bench];
	if (a->size <= 1)
		return ;
	blocks = (a->size + get_block_size(a->size) - 1) / get_block_size(a->size);
	depth = 0;
	while ((1 << depth) < blocks)
		depth++;
	remaining = a->size;
	index = 0;
	while (remaining > 0)
	{
		current = get_block_size(a->size);
		if (remaining < get_block_size(a->size))
			current = remaining;
		sort = [current, get_orientation(index++, depth), is_bench];
		sort_block(a, b, sort, ops);
		remaining -= current;
	}
	merge_all(a, b, ints, ops);
}
