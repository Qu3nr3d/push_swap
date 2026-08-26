/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgirczyc <kgirczyc@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 16:44:41 by kgirczyc          #+#    #+#             */
/*   Updated: 2026/08/23 17:58:15 by kgirczyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

char	*ft_itoa(int n)
{
	int		i;
	char	*str;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = nbr_len(n);
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	str[i--] = '\0';
	while (n > 0)
	{
		str[i--] = (char){n % 10 + 48};
		n /= 10;
	}
	return (str);
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
