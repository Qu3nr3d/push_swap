#include "push_swap.h"

typedef struct s_move
{
	int	a_rot;
	int	b_rot;
	int	cost;
}	t_move;

static int	fits_between(int left, int right, int value)
{
	if (left < right)
		return (left < value && value < right);
	return (value > left || value < right);
}

static int	target_pos_a(t_stack *a, int value)
{
	t_list	*node;
	int		pos;

	if (a->size < 2)
		return (0);
	node = a->first_node;
	pos = 0;
	while (node->next)
	{
		if (fits_between(node->number, node->next->number, value))
			return (pos + 1);
		node = node->next;
		pos++;
	}
	if (fits_between(a->last_node->number,
			a->first_node->number, value))
		return (0);
	return (0);
}

static int	rotation_value(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	return (-(size - pos));
}

static void	build_base(t_stack *a, t_stack *b, t_ops *ops, int is_bench)
{
	int	total;
	int	done;
	int	last;

	total = a->size;
	done = 0;
	last = a->first_node->number;
	while (done < total)
	{
		if (a->first_node->number >= last)
		{
			last = a->first_node->number;
			ra(a, ops, is_bench);
		}
		else
			pb(a, b, ops, is_bench);
		done++;
	}
}

static void	update_best(t_stack *a, t_stack *b,
		int value, int b_pos, t_move *best)
{
	int	a_rot;
	int	b_rot;
	int	a_cost;
	int	b_cost;
	int	cost;

	a_rot = rotation_value(target_pos_a(a, value), a->size);
	b_rot = rotation_value(b_pos, b->size);
	a_cost = (a_rot < 0) ? -a_rot : a_rot;
	b_cost = (b_rot < 0) ? -b_rot : b_rot;
	cost = a_cost + b_cost;
	if (a_rot >= 0 && b_rot >= 0)
		cost = (a_cost > b_cost) ? a_cost : b_cost;
	if (a_rot < 0 && b_rot < 0)
		cost = (a_cost > b_cost) ? a_cost : b_cost;
	if (best->cost < 0 || cost < best->cost)
	{
		best->cost = cost;
		best->a_rot = a_rot;
		best->b_rot = b_rot;
	}
}

static t_move	find_best_move(t_stack *a, t_stack *b)
{
	t_move	best;
	t_list	*node;
	int		pos;

	best.cost = -1;
	node = b->first_node;
	pos = 0;
	while (node)
	{
		update_best(a, b, node->number, pos, &best);
		if (best.cost == 0)
			return (best);
		node = node->next;
		pos++;
	}
	return (best);
}

static void	rotate_both(t_stack *a, t_stack *b,
		t_move *move, t_ops *ops, int is_bench)
{
	while (move->a_rot > 0 && move->b_rot > 0)
	{
		rr(a, b, ops, is_bench);
		move->a_rot--;
		move->b_rot--;
	}
	while (move->a_rot < 0 && move->b_rot < 0)
	{
		rrr(a, b, ops, is_bench);
		move->a_rot++;
		move->b_rot++;
	}
}

static void	execute_move(t_stack *a, t_stack *b,
		t_move move, t_ops *ops, int is_bench)
{
	rotate_both(a, b, &move, ops, is_bench);
	while (move.a_rot > 0)
	{
		ra(a, ops, is_bench);
		move.a_rot--;
	}
	while (move.a_rot < 0)
	{
		rra(a, ops, is_bench);
		move.a_rot++;
	}
	while (move.b_rot > 0)
	{
		rb(b, ops, is_bench);
		move.b_rot--;
	}
	while (move.b_rot < 0)
	{
		rrb(b, ops, is_bench);
		move.b_rot++;
	}
	pa(a, b, ops, is_bench);
}

static void	rotate_min_top(t_stack *a, t_ops *ops, int is_bench)
{
	t_list	*node;
	int		pos;

	node = a->first_node;
	pos = 0;
	while (node && node->next)
	{
		if (node->number > node->next->number)
			break ;
		node = node->next;
		pos++;
	}
	if (!node || !node->next)
		return ;
	pos = rotation_value(pos + 1, a->size);
	if (pos >= 0)
		while (pos-- > 0)
			ra(a, ops, is_bench);
	else
		while (pos++ < 0)
			rra(a, ops, is_bench);
}

void	simple_sort(t_stack *a, t_stack *b, t_ops *ops, int is_bench)
{
	t_list	*node;
	t_move	move;

	if (a->size <= 1)
		return ;
	node = a->first_node;
	while (node->next && node->number < node->next->number)
		node = node->next;
	if (!node->next)
		return ;
	build_base(a, b, ops, is_bench);
	while (b->size > 0)
	{
		move = find_best_move(a, b);
		execute_move(a, b, move, ops, is_bench);
	}
	rotate_min_top(a, ops, is_bench);
}