#include "push_swap.h"

void	ra(t_stack *stack, int *counter)
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
    (*counter)++;
}

void	rb(t_stack *stack, int *counter)
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
    (*counter)++;
}

void	rr(t_stack *stack, int *counter)
{
	ra(stack, counter);
	rb(stack, counter);
}

