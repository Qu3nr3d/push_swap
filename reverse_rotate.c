#include "push_swap.h"

void	rra(t_stack *stack, t_ops *ops)
{
	t_list	*last;

	if (stack->size < 2)
		return;
	last = stack->last_node;
	stack->last_node = last->prev;
	stack->last_node->next = NULL;
	last->prev = NULL;
	last->next = stack->first_node;
	stack->first_node->prev = last;
	stack->first_node = last;
	ops->use_rra++;
	write(1, "rra\n", 4);

}

void	rrb(t_stack *stack, t_ops *ops)
{
	t_list	*last;

	if (stack->size < 2)
		return;
	last = stack->last_node;
	stack->last_node = last->prev;
	stack->last_node->next = NULL;
	last->prev = NULL;
	last->next = stack->first_node;
	stack->first_node->prev = last;
	stack->first_node = last;
	ops->use_rrb++;
	write(1, "rra\n", 4);
}

void rrr(t_stack *stack_a, t_stack *stack_b, t_ops *ops)
{
	rra(stack_a, ops);
	rrb(stack_b, ops);
	ops->use_rrr++;
    write(1, "rrr\n", 4);

}
