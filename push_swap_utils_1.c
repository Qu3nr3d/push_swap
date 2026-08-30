/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacpere <akacpere@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 16:54:36 by kgirczyc          #+#    #+#             */
/*   Updated: 2026/08/31 01:05:55 by akacpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *nptr, int *error)
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

void	print_on_stderr(char *s)
{
	while (*s)
	{
		write(2, s, 1);
		s++;
	}
}

static size_t	nbr_len(int n)
{
	size_t	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
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


