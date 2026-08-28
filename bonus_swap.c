/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacpere <akacpere@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 17:21:47 by kgirczyc          #+#    #+#             */
/*   Updated: 2026/08/28 21:14:25 by akacpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_checker.h"

static int	swap_stack(t_stack *stack)
{
	t_list	*first;
	t_list	*second;

	if (stack->size < 2)
		return (0);
	first = stack->first_node;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	else
		stack->last_node = first;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	stack->first_node = second;
	return (1);
}

void	sa(t_stack *a)
{
	if (!swap_stack(a))
		return ;
}

void	sb(t_stack *b)
{
	if (!swap_stack(b))
		return ;
}

void	ss(t_stack *a, t_stack *b)
{
	int	a_changed;
	int	b_changed;

	a_changed = swap_stack(a);
	b_changed = swap_stack(b);
	if (!a_changed && !b_changed)
		return ;
}
