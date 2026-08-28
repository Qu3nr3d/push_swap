/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacpere <akacpere@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 19:14:42 by akacpere          #+#    #+#             */
/*   Updated: 2026/08/28 21:13:26 by akacpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_checker.h"

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

	if (argc == 1)
		return (3);
	initialize_stacks_and_operation(&s.stack_a, &s.stack_b, &operation);
	if (!parse(argc, argv, &s.stack_a))
		free_all_and_exit(s.stack_a, s.stack_b, operation);
	operation = read_operation(s);
	while (operation)
	{
		if (!is_operation(operation))
			free_all_and_exit(s.stack_a, s.stack_b, operation);
		execute_operation(&s.stack_a, &s.stack_b, operation);
		free(operation);
		operation = read_operation(s);
		if (!operation)
			break ;
	}
	if (s.stack_b.first_node == NULL && is_sorted(s.stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stacks(s.stack_a, s.stack_b);
	return (0);
}
