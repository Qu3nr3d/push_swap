/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacpere <akacpere@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 17:08:01 by kgirczyc          #+#    #+#             */
/*   Updated: 2026/08/31 15:30:40 by akacpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

static bool	add_number(t_stack *stack_a, char *arg)
{
	t_doubly_list	*node;
	int		number;
	int		error;

	number = ft_atoi_with_error(arg, &error);
	if (error)
		return (false);
	if (is_duplicate(stack_a, number))
		return (false);
	node = lstnew(number);
	if (!node)
		return (false);
	lstadd_back(&stack_a->first_node, node);
	stack_a->last_node = node;
	stack_a->size++;
	return (true);
}

static bool	add_arr(t_stack *stack_a, char *s)
{
	char	**arr;
	int		i;

	s = ft_strtrim(s, " ");
	if (!s)
		return (false);
	arr = ft_split(s, ' ');
	free(s);
	if (!arr)
		return (false);
	i = 0;
	while (arr[i])
	{
		if (!add_number(stack_a, arr[i]))
		{
			free_arr(arr);
			return (false);
		}
		i++;
	}
	free_arr(arr);
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
		else if (is_number(args[i]))
		{
			if (!add_number(stack_a, args[i++]))
				return (false);
		}
		else if (is_num_arr(args[i]))
		{
			if (!add_arr(stack_a, args[i++]))
				return (false);
		}
		else
			return (false);
	}
	if (stack_a->size == 0)
		return (false);
	return (true);
}
