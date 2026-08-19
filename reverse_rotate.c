#include "push_swap.h"

static int	reverse_rotate_stack(t_stack *stack)
{
	t_list	*last;

	if (stack->size < 2)
		return (0);
	last = stack->last_node;
	stack->last_node = last->prev;
	stack->last_node->next = NULL;
	last->prev = NULL;
	last->next = stack->first_node;
	stack->first_node->prev = last;
	stack->first_node = last;
	return (1);
}

void	rra(t_stack *a, t_ops *ops, int is_bench)
{
	if (!reverse_rotate_stack(a))
		return ;
	if (is_bench)
		ops->use_rra++;
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b, t_ops *ops, int is_bench)
{
	if (!reverse_rotate_stack(b))
		return ;
	if (is_bench)
		ops->use_rrb++;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b,
		t_ops *ops, int is_bench)
{
	int	a_changed;
	int	b_changed;

	a_changed = reverse_rotate_stack(a);
	b_changed = reverse_rotate_stack(b);
	if (!a_changed && !b_changed)
		return ;
	if (is_bench)
		ops->use_rrr++;
	write(1, "rrr\n", 4);
}
