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

static int	find_max_pos(const t_stack *stack)
{
	t_list	*node;
	int		max;
	int		max_pos;
	int		pos;

	node = stack->first_node;
	max = node->number;
	max_pos = 0;
	pos = 0;
	while (node)
	{
		if (node->number > max)
		{
			max = node->number;
			max_pos = pos;
		}
		node = node->next;
		pos++;
	}
	return (max_pos);
}

static void	move_max_to_top_b(t_stack *stack_b, int *counter)
{
	int	pos;
	int	steps;

	pos = find_max_pos(stack_b);
	if (pos <= stack_b->size / 2)
	{
		while (pos-- > 0)
			rb(stack_b, counter);
	}
	else
	{
		steps = stack_b->size - pos;
		while (steps-- > 0)
			rrb(stack_b, counter);
	}
}

static void	sort_block(t_stack *stack_a, t_stack *stack_b,
		int block_size, int *counter)
{
	int	i;

	i = 0;
	while (i++ < block_size)
		pb(stack_a, stack_b, counter);
	while (stack_b->size > 0)
	{
		move_max_to_top_b(stack_b, counter);
		pa(stack_a, stack_b, counter);
	}
	i = 0;
	while (i++ < block_size)
		ra(stack_a, counter);
}

static void	merge_values(t_stack *stack_a, t_stack *stack_b,
		int *left, int *right, int *counter)
{
	while (*left > 0 && *right > 0)
	{
		if (stack_a->first_node->number < stack_b->last_node->number)
		{
			ra(stack_a, counter);
			(*right)--;
		}
		else
		{
			rrb(stack_b, counter);
			pa(stack_a, stack_b, counter);
			ra(stack_a, counter);
			(*left)--;
		}
	}
	while ((*right)-- > 0)
		ra(stack_a, counter);
	while ((*left)-- > 0)
	{
		rrb(stack_b, counter);
		pa(stack_a, stack_b, counter);
		ra(stack_a, counter);
	}
}

static void	merge_blocks(t_stack *stack_a, t_stack *stack_b,
		int left_size, int right_size, int *counter)
{
	int	left;
	int	right;
	int	i;

	left = left_size;
	right = right_size;
	i = 0;
	while (i++ < left_size)
		pb(stack_a, stack_b, counter);
	merge_values(stack_a, stack_b, &left, &right, counter);
}

static void	merge_pass(t_stack *stack_a, t_stack *stack_b,
	int total_size, int size, int *counter)
{
	int	processed;
	int	right_size;

	processed = 0;
	while (processed < total_size)
	{
		right_size = size;
		if (right_size > total_size - processed - size)
			right_size = total_size - processed - size;
		merge_blocks(stack_a, stack_b, size, right_size, counter);
		processed += size + right_size;
	}
}

static void	merge_all_blocks(t_stack *stack_a, t_stack *stack_b,
		int total_size, int block_size, int *counter)
{
	int	size;

	size = block_size;
	while (size < total_size)
	{
		merge_pass(stack_a, stack_b, total_size, size, counter);
		size *= 2;
	}
}

void	medium_sort(t_stack *stack_a, t_stack *stack_b, int *counter)
{
	int	block_size;
	int	remaining;
	int	current_block_size;

	if (stack_a->size <= 1)
		return ;
	block_size = get_block_size(stack_a->size);
	remaining = stack_a->size;
	while (remaining > 0)
	{
		current_block_size = block_size;
		if (remaining < block_size)
			current_block_size = remaining;
		sort_block(stack_a, stack_b, current_block_size, counter);
		remaining -= current_block_size;
	}
	merge_all_blocks(stack_a, stack_b, stack_a->size, block_size, counter);
}