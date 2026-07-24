#include "push_swap.h"

void	ra(t_stack *taba)
{
	t_list	*tmp;

	t_list tmp = t_stack->first_node;
	t_stack->last_node->next = t_stack->first_node;
	
}