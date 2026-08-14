#include "push_swap.h"

void	ra(t_stack *stack, t_operations *operations)
{
	t_list	*first;

	if (stack->size < 2)
		return;
	first = stack->first_node;
	stack->first_node = first->next;
	stack->first_node->prev = NULL;
	first->next = NULL;
	first->prev = stack->last_node;
	stack->last_node->next = first;
	stack->last_node = first;
	operations->use_ra++;
	write(1, "ra\n", 3);
}

void	rb(t_stack *stack, t_operations *operations)
{
	t_list	*first;

	if (stack->size < 2)
		return;
	first = stack->first_node;
	stack->first_node = first->next;
	stack->first_node->prev = NULL;
	first->next = NULL;
	first->prev = stack->last_node;
	stack->last_node->next = first;
	stack->last_node = first;
	operations->use_rb++;
	write(1, "rb\n", 3);
}

void	rr(t_stack *stack_a, t_stack *stack_b, t_operations *operations)
{
	ra(stack_a, operations);
	rb(stack_b, operations);
	operations->use_rr++;
	write(1, "rr\n", 3);

}

