#include "push_swap.h"

static t_list	*find_next_to_last(t_list *tab, int size)
{
	int		i;
	t_list	*next_to_last;

	next_to_last = tab;
	i = 0;
	while (i < size - 2)
	{
		next_to_last = next_to_last->next;
		i++;
	}
	return (next_to_last);
}

void	rra(t_stack *taba)
{
	t_list	*tmp;

	tmp = taba->last_node;
	taba->last_node->next = taba->first_node;
	taba->last_node = find_next_to_last(taba->first_node, taba->size);
	taba->last_node->next = NULL;
	taba->first_node = tmp;
}

void	rrb(t_stack *tabb)
{
	t_list	*tmp;

	tmp = tabb->last_node;
	tabb->last_node->next = tabb->first_node;
	tabb->last_node = find_next_to_last(tabb->first_node, tabb->size);
	tabb->last_node->next = NULL;
	tabb->first_node = tmp;
}
