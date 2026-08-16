#include "push_swap.h"

void parse(int number_of_args, char *args[], t_stack *stack_a)
{
	int	i;
	t_list *node;

	i = 0;
	node = NULL;
	//popatrzec czy tu sie nie wywala jak jest 1, 2 ,3 argumenty
	while (i < number_of_args && !is_number(args[i]))
		i++;
	while (i < number_of_args && is_number(args[i]))
	{
		node = ft_lstnew(ft_atoi(args[i]));
		if (stack_a->first_node == NULL)
			stack_a->first_node = node;
		else
			ft_lstadd_back(&stack_a->first_node, node);
		stack_a->size++;
		i++;
	}
	stack_a->last_node = node;
}
