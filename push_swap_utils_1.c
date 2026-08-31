/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacpere <akacpere@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 16:54:36 by kgirczyc          #+#    #+#             */
/*   Updated: 2026/08/31 15:36:57 by akacpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_on_stderr(char *s)
{
	while (*s)
	{
		write(2, s, 1);
		s++;
	}
}

bool	str_is_equal(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (false);
		i++;
	}
	if (s1[i] || s2[i])
		return (false);
	return (true);
}

int	ft_atoi_with_error(const char *nptr, int *error)
{
	long long	number;
	int			sign;

	number = 0;
	sign = 1;
	*error = 0;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		number = number * 10 + (*nptr - '0');
		if (number * sign > 2147483647LL || number * sign < -2147483648LL)
			return (*error = 1, 0);
		nptr++;
	}
	return ((int)number * sign);
}

long	round_float(double n)
{
	if (n >= 0)
		return ((long)(n * 100 + 0.5));
	return ((long)(n * 100 - 0.5));
}

int	get_float_len(long x, int neg)
{
	int	len;

	len = 1;
	x /= 100;
	while (x >= 10)
	{
		x /= 10;
		len++;
	}
	return (len + 3 + neg);
}

void	initialize_stacks(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->first_node = NULL;
	stack_a->last_node = NULL;
	stack_a->size = 0;
	stack_b->first_node = NULL;
	stack_b->last_node = NULL;
	stack_b->size = 0;
}

