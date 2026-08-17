/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgirczyc <kgirczyc@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 19:20:27 by kgirczyc          #+#    #+#             */
/*   Updated: 2026/08/17 22:15:54 by kgirczyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder(t_stack stack_a)
{
	int		mistakes;
	int		total_pairs;
	t_list	*node;
	t_list	*tmp;

	mistakes = 0;
	node = stack_a.first_node;
	tmp = NULL;
	while (node)
	{
		tmp = node->next;
		while (tmp)
		{
			if (node->number > tmp->number)
				mistakes++;
			tmp = tmp->next;
		}
		node = node->next;
	}
	total_pairs = stack_a.size * (stack_a.size - 1) / 2;
	if (total_pairs == 0)
		return (0.0f);
	return ((float)mistakes / (float)total_pairs);
}

void	choose_algorithm(t_flags *flags, float disorder)
{
	if (!flags->is_simple && !flags->is_medium && !flags->is_complex)
	{
		if (disorder < 0.2)
			flags->is_simple = 1;
		else if (disorder > 0.2 && disorder < 0.5)
			flags->is_medium = 1;
		else
			flags->is_complex = 1;
	}
}

static long	round_float(double n)
{
	if (n >= 0)
		return ((long)(n * 100 + 0.5));
	return ((long)(n * 100 - 0.5));
}

static int	put_num(char *s, long n, int i)
{
	long	d;

	if (n == 0)
	{
		s[i++] = '0';
		return (i);
	}
	d = 1;
	while (n / d >= 10)
		d *= 10;
	while (d)
	{
		s[i++] = '0' + n / d % 10;
		d /= 10;
	}
	return (i);
}

static int	get_len(long x, int neg)
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

static void	fill_float(char *s, long x, int neg)
{
	int	i;

	i = 0;
	if (neg)
		s[i++] = '-';

	i = put_num(s, x / 100, i);
	s[i++] = '.';
	s[i++] = '0' + x / 10 % 10;
	s[i++] = '0' + x % 10;
	s[i] = '\0';
}

char	*float_to_str(double n)
{
	char	*s;
	long	x;
	int		len;
	int		neg;

	x = round_float(n);
	neg = x < 0;
	if (neg)
		x = -x;
	len = get_len(x, neg);
	s = malloc(len);
	if (!s)
		return (NULL);
	fill_float(s, x, neg);
	return (s);
}
