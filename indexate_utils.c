/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacpere <akacpere@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 17:50:57 by kgirczyc          #+#    #+#             */
/*   Updated: 2026/08/31 15:39:16 by akacpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_number_of_digits(int n)
{
	int	number_of_digits;

	number_of_digits = 0;
	while (n)
	{
		n /= 2;
		number_of_digits++;
	}
	return (number_of_digits);
}

int	find_max_number(t_stack stack)
{
	int		max_number;
	t_doubly_list	*node;

	max_number = INT_MIN;
	node = stack.first_node;
	while (node)
	{
		if (max_number < node->number)
			max_number = node->number;
		node = node->next;
	}
	return (max_number);
}

t_doubly_list	*find_node_with_first_max(t_stack stack, int max)
{
	t_doubly_list	*node;

	node = stack.first_node;
	while (node)
	{
		if (node->number == max)
			return (node);
		node = node->next;
	}
	return (NULL);
}

t_doubly_list	*find_node_with_prev_max(t_stack stack, int *next_max)
{
	int		max_number;
	t_doubly_list	*max_node;
	t_doubly_list	*node;

	max_number = INT_MIN;
	max_node = NULL;
	node = stack.first_node;
	while (node)
	{
		if (node->number < *next_max && max_number < node->number)
		{
			max_number = node->number;
			max_node = node;
		}
		node = node->next;
	}
	*next_max = max_number;
	return (max_node);
}

t_doubly_list	*find_node_with_last_max(t_stack stack)
{
	t_doubly_list	*node;

	node = stack.first_node;
	while (node)
	{
		if (node->index == 0)
			return (node);
		node = node->next;
	}
	return (NULL);
}
