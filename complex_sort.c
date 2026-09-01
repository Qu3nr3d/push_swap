/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacpere <akacpere@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 20:56:40 by akacpere          #+#    #+#             */
/*   Updated: 2026/09/01 14:53:02 by akacpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_number_of_digits(int n)
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

static void	indexate(t_stack *a)
{
	int				i;
	t_doubly_list	*tmp;
	t_doubly_list	*node;

	i = 0;
	node = NULL;
	tmp = a->first_node;
	while (i < a->size)
	{
		while (tmp)
		{
			if (tmp->index == -1)
			{
				if (!node || node->number < tmp->number)
					node = tmp;
			}
			tmp = tmp->next;
		}
		node->index = a->size - i - 1;
		node = NULL;
		tmp = a->first_node;
		i++;
	}
	return ;
}

void	complex_sort(t_stack *a, t_stack *b, t_ops *ops, int is_bench)
{
	int	i;
	int	j;
	int	max_digits;
	int	size;

	i = 0;
	j = 0;
	max_digits = find_number_of_digits(a->size);
	indexate(a);
	size = a->size;
	while (!is_sorted(*a) && (i < max_digits))
	{
		while (a->first_node && j++ < size)
		{
			if ((a->first_node->index & (1 << i)) == 0)
				pb(a, b, ops, is_bench);
			else
				ra(a, ops, is_bench);
		}
		while (b->first_node)
			pa(a, b, ops, is_bench);
		j = 0;
		i++;
	}
	return ;
}
