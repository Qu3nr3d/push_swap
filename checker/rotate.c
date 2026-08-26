/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacpere <akacpere@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 16:58:00 by kgirczyc          #+#    #+#             */
/*   Updated: 2026/08/26 13:00:34 by akacpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	rotate_stack(t_stack *stack)
{
	t_list	*first;

	if (stack->size < 2)
		return (0);
	first = stack->first_node;
	stack->first_node = first->next;
	stack->first_node->prev = NULL;
	first->next = NULL;
	first->prev = stack->last_node;
	stack->last_node->next = first;
	stack->last_node = first;
	return (1);
}

void	ra(t_stack *a)
{
	if (!rotate_stack(a))
		return ;
}

void	rb(t_stack *b)
{
	if (!rotate_stack(b))
		return ;
}

void	rr(t_stack *a, t_stack *b)
{
	int	a_changed;
	int	b_changed;

	a_changed = rotate_stack(a);
	b_changed = rotate_stack(b);
	if (!a_changed && !b_changed)
		return ;
}
