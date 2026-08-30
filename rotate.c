/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacpere <akacpere@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 16:58:00 by kgirczyc          #+#    #+#             */
/*   Updated: 2026/08/31 00:51:55 by akacpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_stack(t_stack *stack)
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

void	ra(t_stack *a, t_ops *ops, int is_bench)
{
	if (!rotate_stack(a))
		return ;
	if (is_bench)
		ops->use_ra++;
	write(1, "ra\n", 3);
}

void	rb(t_stack *b, t_ops *ops, int is_bench)
{
	if (!rotate_stack(b))
		return ;
	if (is_bench)
		ops->use_rb++;
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b, t_ops *ops, int is_bench)
{
	int	a_changed;
	int	b_changed;

	a_changed = rotate_stack(a);
	b_changed = rotate_stack(b);
	if (!a_changed && !b_changed)
		return ;
	if (is_bench)
		ops->use_rr++;
	write(1, "rr\n", 3);
}
