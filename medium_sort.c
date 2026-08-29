/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacpere <akacpere@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 17:54:48 by kgirczyc          #+#    #+#             */
/*   Updated: 2026/08/29 15:10:24 by akacpere         ###   ########.fr       */
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

int	get_orientation(int index, int level)
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

static void	sort_blocks(t_medium *m, int block, int depth)
{
	int	remaining;
	int	current;
	int	index;

	remaining = m->a->size;
	index = 0;
	while (remaining > 0)
	{
		current = block;
		if (remaining < block)
			current = remaining;
		sort_block(m, current, get_orientation(index++, depth));
		remaining -= current;
	}
}

void	medium_sort(t_stack *a, t_stack *b, t_ops *ops, int is_bench)
{
	t_medium	m;
	int			block;
	int			depth;
	int			size;

	if (a->size <= 1 || is_sorted(*a))
		return ;
	m.a = a;
	m.b = b;
	m.ops = ops;
	m.is_bench = is_bench;
	block = get_block_size(a->size);
	depth = 0;
	while ((1 << depth) < (a->size + block - 1) / block)
		depth++;
	sort_blocks(&m, block, depth);
	size = block;
	while (size < a->size)
	{
		depth--;
		merge_pass(&m, a->size, size, depth);
		size *= 2;
	}
}
