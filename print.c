#include "push_swap.h"

typedef struct s_str_ops
{
	char	*str_total_ops;
	char	*str_pa;
	char	*str_pb;
	char	*str_sa;
	char	*str_sb;
	char	*str_ss;
	char	*str_ra;
	char	*str_rb;
	char	*str_rr;
	char	*str_rra;
	char	*str_rrb;
	char	*str_rrr;
} t_str_ops;

int is_error_in_allocation(t_str_ops str_ops)
{
	if (!str_ops.str_total_ops)
		return (1);
	if (!str_ops.str_pa)
		return (1);
	if (!str_ops.str_pb)
		return (1);
	if (!str_ops.str_sa)
		return (1);
	if (!str_ops.str_sb)
		return (1);
	if (!str_ops.str_ss)
		return (1);
	if (!str_ops.str_ra)
		return (1);
	if (!str_ops.str_rb)
		return (1);
	if (!str_ops.str_rr)
		return (1);
	if (!str_ops.str_rra)
		return (1);
	if (!str_ops.str_rrb)
		return (1);
	if (!str_ops.str_rrr)
		return (1);
	return (0);
}


int convert_ops_to_str(t_metrics metrics, t_str_ops *str_ops)
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
		return (0);
	return (1);
}

void print_on_stderr(char *s)
{
	while (*s)
	{
		write(2, s, 1);
		s++;
	}
}

void print_operations(t_str_ops str_ops)
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

void free_str_ops(t_str_ops *str_ops)
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

int print_benchmark(t_metrics metrics)
{
	char		*disorder;
	t_str_ops	str_ops;

	disorder = float_to_str(metrics.disorder * 100);
	if (!disorder)
		return (0);
	if (!convert_ops_to_str(metrics, &str_ops))
		return (0);
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
	return (1);
}
