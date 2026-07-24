#include "push_swap.h"

void	ra(t_stack *taba)
{
	t_list	*tmp;

	tmp = taba->first_node;
	taba->first_node = taba->first_node->next;
	tmp->next = NULL;
	taba->last_node->next = tmp;
	taba->last_node = tmp;
}

void	rb(t_stack *tabb)
{
	t_list	*tmp;

	tmp = tabb->first_node;
	tabb->first_node = tabb->first_node->next;
	tmp->next = NULL;
	tabb->last_node->next = tmp;
	tabb->last_node = tmp;
}
