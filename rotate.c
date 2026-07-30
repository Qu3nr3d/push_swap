#include "push_swap.h"

void	ra(t_list *first, t_list *last)
{
	t_list	*tmp;

	tmp = first;
	first->next->prev = NULL;
	first->next = NULL;
	last->next = first;
}

void	rb(t_list *first, t_list *last)
{
	t_list	*tmp;

	tmp = first;
	first->next->prev = NULL;
	first->next = NULL;
	last->next = first;
}

void	rr(t_list *first_a, t_list *first_b, t_list *last_a, t_list *last_b)
{
	ra(first_a, last_a);
	rb(first_b, last_b);
}

