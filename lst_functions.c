/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacpere <akacpere@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 17:07:30 by kgirczyc          #+#    #+#             */
/*   Updated: 2026/08/31 23:46:08 by akacpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_doubly_list	*lstnew(int number)
{
	t_doubly_list	*new_node;

	new_node = calloc(1, sizeof(t_doubly_list));
	if (!new_node)
		return (NULL);
	new_node->number = number;
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->index = 0;
	return (new_node);
}

int	lstsize(t_doubly_list *lst)
{
	t_doubly_list	*current_node;
	int				len;

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

t_doubly_list	*lstlast(t_doubly_list *lst)
{
	int				len;
	t_doubly_list	*last_node;

	if (!lst)
		return (NULL);
	len = lstsize(lst);
	last_node = lst;
	while (len > 1)
	{
		last_node = last_node->next;
		len --;
	}
	return (last_node);
}

void	lstadd_back(t_doubly_list **lst, t_doubly_list *new)
{
	t_doubly_list	*last;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = lstlast(*lst);
	last->next = new;
	new->prev = last;
}

void	lstclear(t_doubly_list **lst)
{
	t_doubly_list	*current;
	t_doubly_list	*tmp;

	if (!lst | !*lst)
		return ;
	current = *lst;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	*lst = NULL;
}
