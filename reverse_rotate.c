#include "push_swap.h"

void	rra(t_list *first, t_list *last)
{
	t_list	*tmp;

	tmp = last;
	last->prev->next = NULL;
	last->prev = NULL;
	first->prev = last;
	last->next = first;
}

void	rrb(t_list *first, t_list *last)
{
	t_list	*tmp;

	tmp = last;
	last->prev->next = NULL;
	last->prev = NULL;
	first->prev = last;
	last->next = first;
}

void rrr(t_list *first_a, t_list *last_a, t_list *first_b, t_list *last_b)
{
	rra(first_a, last_a);
	rrb(first_b, last_b);
}
