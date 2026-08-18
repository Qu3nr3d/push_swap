#include "push_swap.h"

char *create_strategy_str(t_flags flags)
{
	char *strategy;

	if (flags.is_simple)
	{
		if (!flags.is_adaptive)
			strategy = ft_strdup("Simple / O(n^2)");
		else
			strategy = ft_strdup("Adaptive / O(n^2)");
	}
	else if (flags.is_medium)
	{
		if (!flags.is_adaptive)
			strategy = ft_strdup("Medium / O(n√n)");
		else
			strategy = ft_strdup("Adaptive / O(n√n)");
	}
	else
	{
		if (!flags.is_adaptive)
			strategy = ft_strdup("Complex / O(nlogn)");
		else
			strategy = ft_strdup("Adaptive / O(nlogn)");
	}
	return (strategy);
}

int initialize_metrics(t_metrics *metrics, t_flags flags, t_stack stack_a)
{
	metrics->disorder = compute_disorder(stack_a);
	metrics->strategy = create_strategy_str(flags);
	if (!metrics->strategy)
		return (0);
	metrics->total_ops = 0;
	metrics->ops = initialize_ops();
	return (1);
}

void update_metrics(t_metrics *metrics)
{
	metrics->total_ops = metrics->ops.use_sa + metrics->ops.use_sb + \
	metrics->ops.use_ss + metrics->ops.use_pa + metrics->ops.use_pb + \
	metrics->ops.use_ra + metrics->ops.use_rb + metrics->ops.use_rr + \
	metrics->ops.use_rra + metrics->ops.use_rrb + metrics->ops.use_rrr;
}