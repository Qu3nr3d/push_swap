#include "push_swap.h"

void print_on_stderr(char *s)
{
	while (*s)
	{
		write(2, s, 1);
		s++;
	}
}

void print_operations(t_metrics metrics)
{
	print_on_stderr("[bench] sa: ");
	print_on_stderr(ft_itoa(metrics.ops.use_sa));
	print_on_stderr(" sb: ");
	print_on_stderr(ft_itoa(metrics.ops.use_sb));
	print_on_stderr(" ss: ");
	print_on_stderr(ft_itoa(metrics.ops.use_ss));
	print_on_stderr(" pa: ");
	print_on_stderr(ft_itoa(metrics.ops.use_pa));
	print_on_stderr(" pb: ");
	print_on_stderr(ft_itoa(metrics.ops.use_pb));
	print_on_stderr("\n");
	print_on_stderr("[bench] ra: ");
	print_on_stderr(ft_itoa(metrics.ops.use_ra));
	print_on_stderr(" rb: ");
	print_on_stderr(ft_itoa(metrics.ops.use_rb));
	print_on_stderr(" rr: ");
	print_on_stderr(ft_itoa(metrics.ops.use_rr));
	print_on_stderr(" rra: ");
	print_on_stderr(ft_itoa(metrics.ops.use_rra));
	print_on_stderr(" rrb: ");
	print_on_stderr(ft_itoa(metrics.ops.use_rrb));
	print_on_stderr(" rrr: ");
	print_on_stderr(ft_itoa(metrics.ops.use_rrr));
	print_on_stderr("\n");
}

void print_benchmark(t_metrics metrics)
{
	char *disorder;

	disorder = float_to_str(metrics.disorder * 100);
	if (!disorder)
		return ;
	print_on_stderr("[bench] disorder: ");
	print_on_stderr(disorder);
	print_on_stderr("%\n");
	free(disorder);
	print_on_stderr("[bench] strategy: ");
	print_on_stderr(metrics.strategy);
	print_on_stderr("\n");
	print_on_stderr("[bench] total_ops: ");
	print_on_stderr(ft_itoa(metrics.total_ops));
	print_on_stderr("\n");
	print_operations(metrics);
}
