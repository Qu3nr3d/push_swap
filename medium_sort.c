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

static void	move_extreme_top_b(t_stack *b, int ascending, t_ops *ops, int is_bench)
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

static void	sort_block(t_stack *a, t_stack *b,
		int size, int ascending, t_ops *ops, int is_bench)
{
	int	i;

	i = 0;
	while (i++ < size)
		pb(a, b, ops, is_bench);
	while (b->size > 0)
	{
		move_extreme_top_b(b, ascending, ops, is_bench);
		pa(a, b, ops, is_bench);
	}
	i = 0;
	while (i++ < size)
		ra(a, ops, is_bench);
}

static void	merge_values(t_stack *a, t_stack *b,
		t_merge *merge, t_ops *ops, int is_bench)
{
	while (merge->left > 0 && merge->right > 0)
	{
		if ((merge->ascending
				&& a->first_node->number < b->first_node->number)
			|| (!merge->ascending
				&& a->first_node->number > b->first_node->number))
		{
			ra(a, ops, is_bench);
			merge->right--;
		}
		else
		{
			pa(a, b, ops, is_bench);
			ra(a, ops, is_bench);
			merge->left--;
		}
	}
	while (merge->right-- > 0)
		ra(a, ops, is_bench);
	while (merge->left-- > 0)
	{
		pa(a, b, ops, is_bench);
		ra(a, ops, is_bench);
	}
}

static void	merge_pass(t_stack *a, t_stack *b,
		int total, int size, int level, t_ops *ops, int is_bench)
{
	t_merge	merge;
	int		processed;
	int		pair;
	int		right_size;
	int		i;

	processed = 0;
	pair = 0;
	while (processed < total)
	{
		right_size = size;
		if (right_size > total - processed - size)
			right_size = total - processed - size;
		merge.left = size;
		merge.right = right_size;
		merge.ascending = get_orientation(pair, level);
		i = 0;
		while (i++ < size)
			pb(a, b, ops, is_bench);
		merge_values(a, b, &merge, ops, is_bench);
		processed += size + right_size;
		pair++;
	}
}

static void	merge_all(t_stack *a, t_stack *b,
		int total, int block_size, int depth, t_ops *ops, int is_bench)
{
	int	size;
	int	level;

	size = block_size;
	level = depth - 1;
	while (size < total)
	{
		merge_pass(a, b, total, size, level, ops, is_bench);
		size *= 2;
		level--;
	}
}

void	medium_sort(t_stack *a, t_stack *b, t_ops *ops, int is_bench)
{
	int	block;
	int	remaining;
	int	current;
	int	blocks;
	int	depth;
	int	index;

	if (a->size <= 1)
		return ;
	block = get_block_size(a->size);
	blocks = (a->size + block - 1) / block;
	depth = 0;
	while ((1 << depth) < blocks)
		depth++;
	remaining = a->size;
	index = 0;
	while (remaining > 0)
	{
		current = block;
		if (remaining < block)
			current = remaining;
		sort_block(a, b, current,
			get_orientation(index++, depth), ops, is_bench);
		remaining -= current;
	}
	merge_all(a, b, a->size, block, depth, ops, is_bench);
}