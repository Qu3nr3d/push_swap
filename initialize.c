#include "push_swap.h"

// initialize_flags is located in flags.c
void initialize_stacks (t_stack *stack_a, t_stack *stack_b)
{
	stack_a->first_node = NULL;
	stack_a->last_node = NULL;
	stack_a->size = 0;
	stack_b->first_node = NULL;
	stack_b->last_node = NULL;
	stack_b->size = 0;
}

t_ops initialize_ops()
{
	t_ops ops;

	ops.use_pa = 0;
	ops.use_pb = 0;
	ops.use_sa = 0;
	ops.use_sb = 0;
	ops.use_ss = 0;
	ops.use_ra = 0;
	ops.use_rb = 0;
	ops.use_rr = 0;
	ops.use_rra = 0;
	ops.use_rrb = 0;
	ops.use_rrr = 0;
	return (ops);
}

void initialize_metrics(t_metrics *metrics, t_flags flags, t_stack stack_a)
{
	metrics->disorder = compute_disorder(stack_a);
	metrics->strategy = choose_strategy(flags, metrics->disorder);
	metrics->total_ops = 0;
	metrics->ops = initialize_ops();
}