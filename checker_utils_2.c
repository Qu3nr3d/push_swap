/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacpere <akacpere@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 23:39:49 by akacpere          #+#    #+#             */
/*   Updated: 2026/09/01 13:34:16 by akacpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	execute_operation_1(t_stack *a, t_stack *b, char *s)
{
	if (str_is_equal(s, "sa\n"))
		swap_stack(a);
	if (str_is_equal(s, "sb\n"))
		swap_stack(b);
	if (str_is_equal(s, "ss\n"))
	{
		swap_stack(a);
		swap_stack(b);
	}
	if (str_is_equal(s, "pa\n"))
		push_stack(a, b);
	if (str_is_equal(s, "pb\n"))
		push_stack(b, a);
	return ;
}

void	execute_operation_2(t_stack *a, t_stack *b, char *s)
{
	if (str_is_equal(s, "ra\n"))
		rotate_stack(a);
	if (str_is_equal(s, "rb\n"))
		rotate_stack(b);
	if (str_is_equal(s, "rr\n"))
	{
		rotate_stack(a);
		rotate_stack(b);
	}
	if (str_is_equal(s, "rra\n"))
		reverse_rotate_stack(a);
	if (str_is_equal(s, "rrb\n"))
		reverse_rotate_stack(b);
	if (str_is_equal(s, "rrr\n"))
	{
		reverse_rotate_stack(a);
		reverse_rotate_stack(b);
	}
	return ;
}
