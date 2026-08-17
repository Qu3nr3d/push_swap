#include "push_swap.h"

int	is_number(char *str)
{
	int	i;

	if (!str || !str[0])
		return (0);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void initialize_stacks (t_stack *stack_a, t_stack *stack_b)
{
	stack_a->first_node = NULL;
	stack_a->last_node = NULL;
	stack_a->size = 0;
	stack_b->first_node = NULL;
	stack_b->last_node = NULL;
	stack_b->size = 0;
}

int	ft_atoi(const char *nptr, int *error)
{
	long long number;
	int	sign;

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

char *choose_strategy(t_flags flags, float disorder)
{
	char *strategy;

	if (!flags.is_simple && !flags.is_medium && !flags.is_complex)
	{
		if (disorder < 0.2)
			flags.is_simple = 1;
		else if (disorder > 0.2 && disorder < 0.5)
			flags.is_medium = 1;
		else
			flags.is_complex = 1;
	}
	if (flags.is_simple)
		strategy = ft_strdup("Simple / O(n^2)");
	else if (flags.is_medium)
		strategy = ft_strdup("Medium / O(n\xFBn)");
	else
		strategy = ft_strdup("Complex / O(nlogn)");
	return (strategy);
}

t_operations initialize_operations()
{
	t_operations operations;

	operations.use_pa = 0;
	operations.use_pb = 0;
	operations.use_sa = 0;
	operations.use_sb = 0;
	operations.use_ss = 0;
	operations.use_ra = 0;
	operations.use_rb = 0;
	operations.use_rr = 0;
	operations.use_rra = 0;
	operations.use_rrb = 0;
	operations.use_rrr = 0;
	return (operations);
}

void initialize_metrics(t_metrics *metrics, t_flags flags, t_stack stack_a)
{
	metrics->disorder = compute_disorder(stack_a);
	metrics->strategy = choose_strategy(flags, metrics->disorder);
	metrics->total_ops = 0;
	metrics->operations = initialize_operations();
}
