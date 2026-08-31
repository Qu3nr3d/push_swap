/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacpere <akacpere@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 16:55:19 by kgirczyc          #+#    #+#             */
/*   Updated: 2026/08/31 15:36:42 by akacpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_strategy(t_flags *flags)
{
	if (flags->is_simple || flags->is_medium
		|| flags->is_complex || flags->is_adaptive)
		return (true);
	return (false);
}

bool	is_flag(char *str)
{
	if (str_is_equal("--bench", str))
		return (true);
	if (str_is_equal("--simple", str))
		return (true);
	if (str_is_equal("--medium", str))
		return (true);
	if (str_is_equal("--complex", str))
		return (true);
	if (str_is_equal("--adaptive", str))
		return (true);
	return (false);
}

static bool	check_flags(char *str, t_flags *flags)
{
	if (str_is_equal("--bench", str))
	{
		if (flags->is_bench)
			return (false);
		flags->is_bench = 1;
	}
	else if (is_flag(str))
	{
		if (check_strategy(flags))
			return (false);
		else if (str_is_equal("--simple", str))
			flags->is_simple = 1;
		else if (str_is_equal("--medium", str))
			flags->is_medium = 1;
		else if (str_is_equal("--complex", str))
			flags->is_complex = 1;
		else
			flags->is_adaptive = 1;
	}
	return (true);
}

bool	initialize_flags(int argc, char *args[], t_flags *flags)
{
	int	i;

	i = 0;
	flags->is_bench = 0;
	flags->is_simple = 0;
	flags->is_medium = 0;
	flags->is_complex = 0;
	flags->is_adaptive = 0;
	while (i < argc)
	{
		if (is_flag(args[i]) && !check_flags(args[i], flags))
			return (false);
		i++;
	}
	if (!flags->is_simple && !flags->is_medium && !flags->is_complex)
		flags->is_adaptive = 1;
	return (true);
}
