/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacpere@student.42warsaw.pl <akacpere>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 17:08:01 by kgirczyc          #+#    #+#             */
/*   Updated: 2026/08/25 16:23:17 by akacpere@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_duplicate(t_stack *stack, int number)
{
	t_list	*node;

	node = stack->first_node;
	while (node)
	{
		if (node->number == number)
			return (true);
		node = node->next;
	}
	return (false);
}

static bool	add_number(t_stack *stack_a, char *arg)
{
	t_list	*node;
	int		number;
	int		error;

	number = ft_atoi(arg, &error);
	if (error)
		return (false);
	if (is_duplicate(stack_a, number))
		return (false);
	node = ft_lstnew(number);
	if (!node)
		return (false);
	ft_lstadd_back(&stack_a->first_node, node);
	stack_a->last_node = node;
	stack_a->size++;
	return (true);
}

bool	parse(int argc, char *args[], t_stack *stack_a)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (is_flag(args[i]))
			i++;
		else if (!is_number(args[i]))
			return (false);
		else if (!add_number(stack_a, args[i++]))
			return (false);
	}
	if (stack_a->size == 0)
		return (false);
	return (true);
}
