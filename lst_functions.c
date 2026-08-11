#include "push_swap.h"

t_list	*ft_lstnew(int number)
{
	t_list	*new_node;

	new_node = calloc(1, sizeof(t_list));
	if (!new_node)
		return(NULL);
	new_node->number = number;
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->index = 0;
	return (new_node);
}

int	ft_lstsize(t_list *lst)
{
	t_list	*current_node;
	int		len;

	if (!lst)
		return (0);
	current_node = lst;
	len = 0;
	while (current_node)
	{
		current_node = current_node->next;
		len++;
	}
	return (len);
}

t_list	*ft_lstlast(t_list *lst)
{
	int		len;
	t_list	*last_node;

	if (!lst)
		return (NULL);
	len = ft_lstsize(lst);
	last_node = lst;
	while (len > 1)
	{
		last_node = last_node->next;
		len --;
	}
	return (last_node);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
	new->prev = last;
}