#include "push_swap.h"

//zabezpieczyc NULL
void	ra(t_stack *stack)
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
}

void	rb(t_stack *stack)
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
}

void	rr(t_stack *stack)
{
	ra(stack);
	rb(stack);
}

