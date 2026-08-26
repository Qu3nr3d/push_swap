/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacpere@student.42warsaw.pl <akacpere>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 17:17:02 by kgirczyc          #+#    #+#             */
/*   Updated: 2026/08/25 16:35:01 by akacpere@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_error_in_allocation(t_str_ops str_ops)
{
	if (!str_ops.str_total_ops || !str_ops.str_pa)
		return (true);
	if (!str_ops.str_pb)
		return (true);
	if (!str_ops.str_sa)
		return (true);
	if (!str_ops.str_sb)
		return (true);
	if (!str_ops.str_ss)
		return (true);
	if (!str_ops.str_ra)
		return (true);
	if (!str_ops.str_rb)
		return (true);
	if (!str_ops.str_rr)
		return (true);
	if (!str_ops.str_rra)
		return (true);
	if (!str_ops.str_rrb)
		return (true);
	if (!str_ops.str_rrr)
		return (true);
	return (false);
}

static bool	convert_ops_to_str(t_metrics metrics, t_str_ops *str_ops)
{
	str_ops->str_total_ops = ft_itoa(metrics.total_ops);
	str_ops->str_pa = ft_itoa(metrics.ops.use_pa);
	str_ops->str_pb = ft_itoa(metrics.ops.use_pb);
	str_ops->str_sa = ft_itoa(metrics.ops.use_sa);
	str_ops->str_sb = ft_itoa(metrics.ops.use_sb);
	str_ops->str_ss = ft_itoa(metrics.ops.use_ss);
	str_ops->str_ra = ft_itoa(metrics.ops.use_ra);
	str_ops->str_rb = ft_itoa(metrics.ops.use_rb);
	str_ops->str_rr = ft_itoa(metrics.ops.use_rr);
	str_ops->str_rra = ft_itoa(metrics.ops.use_rra);
	str_ops->str_rrb = ft_itoa(metrics.ops.use_rrb);
	str_ops->str_rrr = ft_itoa(metrics.ops.use_rrr);
	if (is_error_in_allocation(*str_ops))
		return (false);
	return (true);
}

static void	print_operations(t_str_ops str_ops)
{
	print_on_stderr("[bench] sa: ");
	print_on_stderr(str_ops.str_sa);
	print_on_stderr(" sb: ");
	print_on_stderr(str_ops.str_sb);
	print_on_stderr(" ss: ");
	print_on_stderr(str_ops.str_ss);
	print_on_stderr(" pa: ");
	print_on_stderr(str_ops.str_pa);
	print_on_stderr(" pb: ");
	print_on_stderr(str_ops.str_pb);
	print_on_stderr("\n");
	print_on_stderr("[bench] ra: ");
	print_on_stderr(str_ops.str_ra);
	print_on_stderr(" rb: ");
	print_on_stderr(str_ops.str_rb);
	print_on_stderr(" rr: ");
	print_on_stderr(str_ops.str_rr);
	print_on_stderr(" rra: ");
	print_on_stderr(str_ops.str_rra);
	print_on_stderr(" rrb: ");
	print_on_stderr(str_ops.str_rrb);
	print_on_stderr(" rrr: ");
	print_on_stderr(str_ops.str_rrr);
	print_on_stderr("\n");
}

static void	free_str_ops(t_str_ops *str_ops)
{
	free(str_ops->str_total_ops);
	str_ops->str_total_ops = NULL;
	free(str_ops->str_pa);
	str_ops->str_pa = NULL;
	free(str_ops->str_pb);
	str_ops->str_pb = NULL;
	free(str_ops->str_sa);
	str_ops->str_sa = NULL;
	free(str_ops->str_sb);
	str_ops->str_sb = NULL;
	free(str_ops->str_ss);
	str_ops->str_ss = NULL;
	free(str_ops->str_ra);
	str_ops->str_ra = NULL;
	free(str_ops->str_rb);
	str_ops->str_rb = NULL;
	free(str_ops->str_rr);
	str_ops->str_rr = NULL;
	free(str_ops->str_rra);
	str_ops->str_rra = NULL;
	free(str_ops->str_rrb);
	str_ops->str_rrb = NULL;
	free(str_ops->str_rrr);
	str_ops->str_rrr = NULL;
}

bool	print_benchmark(t_metrics metrics)
{
	char		*disorder;
	t_str_ops	str_ops;

	disorder = float_to_str(metrics.disorder * 100);
	if (!disorder)
		return (false);
	if (!convert_ops_to_str(metrics, &str_ops))
		return (false);
	print_on_stderr("[bench] disorder: ");
	print_on_stderr(disorder);
	print_on_stderr("%\n");
	free(disorder);
	print_on_stderr("[bench] strategy: ");
	print_on_stderr(metrics.strategy);
	print_on_stderr("\n");
	free(metrics.strategy);
	print_on_stderr("[bench] total_ops: ");
	print_on_stderr((str_ops.str_total_ops));
	print_on_stderr("\n");
	print_operations(str_ops);
	free_str_ops(&str_ops);
	return (true);
}
