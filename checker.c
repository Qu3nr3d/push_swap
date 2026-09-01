/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacpere <akacpere@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 23:39:39 by akacpere          #+#    #+#             */
/*   Updated: 2026/09/01 14:15:56 by akacpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	arg_is_flag(int argc, char *args[])
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (is_flag(args[i]) || str_is_equal("--bench", args[i]))
		{
			write(2, "Error\n", 6);
			return (true);
		}
		i++;
	}
	return (false);
}

static void	free_all_and_exit(t_stack stack_a, t_stack stack_b, char *operation)
{
	if (operation)
		free(operation);
	free_stacks_and_exit(stack_a, stack_b);
}

int	main(int argc, char *argv[])
{
	t_stacks	s;
	char		*operation;

	while (argc == 1 || arg_is_flag(argc, argv))
		return (1);
	operation = read_operation(s);
	init_stacks(&s.stack_a, &s.stack_b);
	if (!parse(argc, argv, &s.stack_a))
		free_all_and_exit(s.stack_a, s.stack_b, operation);
	while (operation)
	{
		if (!is_operation(operation))
			free_all_and_exit(s.stack_a, s.stack_b, operation);
		execute_operation_1(&s.stack_a, &s.stack_b, operation);
		execute_operation_2(&s.stack_a, &s.stack_b, operation);
		free(operation);
		operation = read_operation(s);
	}
	if (s.stack_b.first_node == NULL && is_sorted(s.stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (free_stacks(s.stack_a, s.stack_b), 0);
}
