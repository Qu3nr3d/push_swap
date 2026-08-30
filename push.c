/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacpere <akacpere@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 16:40:14 by kgirczyc          #+#    #+#             */
/*   Updated: 2026/08/31 00:57:18 by akacpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int push_stack(t_stack *pushed_to, t_stack *pushed_from)
{
	t_list	*p;

	if (pushed_from->size == 0)
		return (0);
	p = pushed_from->first_node;
	pushed_from->first_node = p->next;
	if (pushed_from->first_node != NULL)
		pushed_from->first_node->prev = NULL;
	else
		pushed_from->last_node = NULL;
	p->next = a->first_node;
	p->prev = NULL;
	if (pushed_toa->first_node != NULL)
		pushed_to->first_node->prev = p;
	else
		pushed_to->last_node = p;
	pushed_to->first_node = p;
	pushed_to->size++;
	pushed_from->size--;
	return (1);
}

void	pa(t_stack *a, t_stack *b, t_ops *ops, int is_bench)
{
	if (!push_stack(a, b))
		return ;
	if (is_bench)
		ops->use_pa++;
	write (1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b, t_ops *ops, int is_bench)
{
	if (!push_stack(b, a))
		return ;
	if (is_bench)
		ops->use_pb++;
	write (1, "pb\n", 3);
}
