#include "push_swap.h"

void print_str_on_stderr(char *s)
{
	while (*s)
	{
		write(2, s, 1);
		s++;
	}
}

void print_int_on_stderr(int n)
{
	char *s;

	s = ft_itoa(n);
	print_str_on_stderr(s);
	free(s);
}

void print_operations(t_metrics metrics)
{
	print_str_on_stderr("[bench] sa: ");
	print_int_on_stderr(metrics.ops.use_sa);
	print_str_on_stderr(" sb: ");
	print_int_on_stderr(metrics.ops.use_sb);
	print_str_on_stderr(" ss: ");
	print_int_on_stderr(metrics.ops.use_ss);
	print_str_on_stderr(" pa: ");
	print_int_on_stderr(metrics.ops.use_pa);
	print_str_on_stderr(" pb: ");
	print_int_on_stderr(metrics.ops.use_pb);
	print_str_on_stderr("\n");
	print_str_on_stderr("[bench] ra: ");
	print_int_on_stderr(metrics.ops.use_ra);
	print_str_on_stderr(" rb: ");
	print_int_on_stderr(metrics.ops.use_rb);
	print_str_on_stderr(" rr: ");
	print_int_on_stderr(metrics.ops.use_rr);
	print_str_on_stderr(" rra: ");
	print_int_on_stderr(metrics.ops.use_rra);
	print_str_on_stderr(" rrb: ");
	print_int_on_stderr(metrics.ops.use_rrb);
	print_str_on_stderr(" rrr: ");
	print_int_on_stderr(metrics.ops.use_rrr);
	print_str_on_stderr("\n");
}

void print_benchmark(t_metrics metrics)
{
	char *disorder;

	disorder = float_to_str(metrics.disorder * 100);
	if (!disorder)
		return ;
	print_str_on_stderr("[bench] disorder: ");
	print_str_on_stderr(disorder);
	print_str_on_stderr("%\n");
	free(disorder);
	print_str_on_stderr("[bench] strategy: ");
	print_str_on_stderr(metrics.strategy);
	print_str_on_stderr("\n");
	free(metrics.strategy);
	print_str_on_stderr("[bench] total_ops: ");
	print_int_on_stderr((metrics.total_ops));
	print_str_on_stderr("\n");
	print_operations(metrics);
}