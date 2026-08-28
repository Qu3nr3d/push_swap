/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker_utils_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacpere <akacpere@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 20:39:17 by akacpere          #+#    #+#             */
/*   Updated: 2026/08/28 21:13:37 by akacpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_checker.h"

bool	str_is_equal(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s1[i] || s2[i])
		return (false);
	return (true);
}

bool	is_operation(char *s)
{
	if (str_is_equal(s, "sa\n"))
		return (true);
	if (str_is_equal(s, "sb\n"))
		return (true);
	if (str_is_equal(s, "ss\n"))
		return (true);
	if (str_is_equal(s, "pa\n"))
		return (true);
	if (str_is_equal(s, "pb\n"))
		return (true);
	if (str_is_equal(s, "ra\n"))
		return (true);
	if (str_is_equal(s, "rb\n"))
		return (true);
	if (str_is_equal(s, "rr\n"))
		return (true);
	if (str_is_equal(s, "rra\n"))
		return (true);
	if (str_is_equal(s, "rrb\n"))
		return (true);
	if (str_is_equal(s, "rrr\n"))
		return (true);
	return (false);
}

void	execute_operation(t_stack *a, t_stack *b, char *s)
{
	if (str_is_equal(s, "sa\n"))
		sa(a);
	if (str_is_equal(s, "sb\n"))
		sb(b);
	if (str_is_equal(s, "ss\n"))
		ss(a, b);
	if (str_is_equal(s, "pa\n"))
		pa(a, b);
	if (str_is_equal(s, "pb\n"))
		pb(a, b);
	if (str_is_equal(s, "ra\n"))
		ra(a);
	if (str_is_equal(s, "rb\n"))
		rb(b);
	if (str_is_equal(s, "rr\n"))
		rr(a, b);
	if (str_is_equal(s, "rra\n"))
		rra(a);
	if (str_is_equal(s, "rrb\n"))
		rrb(b);
	if (str_is_equal(s, "rrr\n"))
		rrr(a, b);
	return ;
}

int	is_sorted(t_stack a)
{
	t_list	*node;

	node = a.first_node;
	while (node->next)
	{
		if (node->number > node->next->number)
			return (0);
		node = node->next;
	}
	return (1);
}
