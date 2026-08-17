#include "push_swap.h"

static int is_duplicate(t_stack *stack, int number) {
	t_list *node;

	node = stack->first_node;
	while (node) {
		if (node->number == number)
			return (1);
		node = node->next;
	}
	return (0);
}

static int add_number(t_stack *stack_a, char *arg) {
	t_list *node;
	int number;
	int error;

	number = ft_atoi(arg, &error);
	if (error)
		return (0);
	if (is_duplicate(stack_a, number))
		return (0);
	node = ft_lstnew(number);
	if (!node)
		return(0);
	ft_lstadd_back(&stack_a->first_node, node);
	stack_a->last_node = node;
	stack_a->size++;
	return (1);
}

int parse(int argc, char *args[], t_stack *stack_a)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (is_flag(args[i]))
			i++;
		else if (!is_number(args[i]))
			return (0);
		else if (!add_number(stack_a, args[i++]))
			return (0);
	}
	if (stack_a->size == 0)
		return (0);
	return (1);
}