#include "push_swap.h"

//zabezpieczyc NULL
void	rra(t_list **first, t_list **last)
{
	t_list	*tmp;

	if (*first == *last)
		return;
	tmp = *last;
	*last = (*last)->prev;
	(*last)->next = NULL;
	tmp->prev = NULL;
	tmp->next = *first;
	(*first)->prev = tmp;
	*first = tmp;
}

void	rrb(t_list **first, t_list **last)
{
	t_list	*tmp;

	if (*first == *last)
		return;
	tmp = *last;
	*last = (*last)->prev;
	(*last)->next = NULL;
	tmp->prev = NULL;
	tmp->next = *first;
	(*first)->prev = tmp;
	*first = tmp;
}

void rrr(t_list **first_a, t_list **last_a, t_list **first_b, t_list **last_b)
{
	rra(first_a, last_a);
	rrb(first_b, last_b);
}
