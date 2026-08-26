/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacpere <akacpere@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 16:57:42 by kgirczyc          #+#    #+#             */
/*   Updated: 2026/08/26 13:01:10 by akacpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	reverse_rotate_stack(t_stack *stack)
{
	t_list	*last;

	if (stack->size < 2)
		return (0);
	last = stack->last_node;
	stack->last_node = last->prev;
	stack->last_node->next = NULL;
	last->prev = NULL;
	last->next = stack->first_node;
	stack->first_node->prev = last;
	stack->first_node = last;
	return (1);
}

void	rra(t_stack *a)
{
	if (!reverse_rotate_stack(a))
		return ;
}

void	rrb(t_stack *b)
{
	if (!reverse_rotate_stack(b))
		return ;
}

void	rrr(t_stack *a, t_stack *b)
{
	int	a_changed;
	int	b_changed;

	a_changed = reverse_rotate_stack(a);
	b_changed = reverse_rotate_stack(b);
	if (!a_changed && !b_changed)
		return ;
}
