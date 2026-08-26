/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacpere <akacpere@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 16:40:14 by kgirczyc          #+#    #+#             */
/*   Updated: 2026/08/26 12:59:12 by akacpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	pa(t_stack *a, t_stack *b)
{
	t_list	*p;

	if (b->size == 0)
		return ;
	p = b->first_node;
	b->first_node = p->next;
	if (b->first_node != NULL)
		b->first_node->prev = NULL;
	else
		b->last_node = NULL;
	p->next = a->first_node;
	p->prev = NULL;
	if (a->first_node != NULL)
		a->first_node->prev = p;
	else
		a->last_node = p;
	a->first_node = p;
	a->size++;
	b->size--;
}

void	pb(t_stack *a, t_stack *b)
{
	t_list	*p;

	if (a->size == 0)
		return ;
	p = a->first_node;
	a->first_node = p->next;
	if (a->first_node != NULL)
		a->first_node->prev = NULL;
	else
		a->last_node = NULL;
	p->next = b->first_node;
	p->prev = NULL;
	if (b->first_node != NULL)
		b->first_node->prev = p;
	else
		b->last_node = p;
	b->first_node = p;
	b->size++;
	a->size--;
}
