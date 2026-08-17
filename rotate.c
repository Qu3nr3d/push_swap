#include "push_swap.h"

static int	rotate_stack(t_stack *stack)
{
	t_list	*first;

	if (stack->size < 2)
		return (0);
	first = stack->first_node;
	stack->first_node = first->next;
	stack->first_node->prev = NULL;
	first->next = NULL;
	first->prev = stack->last_node;
	stack->last_node->next = first;
	stack->last_node = first;
	return (1);
}

void	ra(t_stack *stack, t_ops *ops)
{
	if (!rotate_stack(stack))
		return ;
	ops->use_ra++;
	write(1, "ra\n", 3);
}

void	rb(t_stack *stack, t_ops *ops)
{
	if (!rotate_stack(stack))
		return ;
	ops->use_rb++;
	write(1, "rb\n", 3);
}

void	rr(t_stack *stack_a, t_stack *stack_b, t_ops *ops)
{
	int	a_changed;
	int	b_changed;

	a_changed = rotate_stack(stack_a);
	b_changed = rotate_stack(stack_b);
	if (!a_changed && !b_changed)
		return ;
	ops->use_rr++;
	write(1, "rr\n", 3);
}