#include "checker.h"
#include <stdio.h>

void	display_stack(t_list *tab)
{
	t_list	*node;

	node = tab;
	while (node)
	{
		printf("| ");
		printf("%d", node->number);
		printf(" |");
		node = node->next;
		printf("\n");
	}
	printf("\n");
}

static void free_and_exit(t_stack stack_a, t_stack stack_b, char *operation)
{
	if (stack_a.first_node)
		ft_lstclear(&stack_a.first_node);
	if (stack_b.first_node)
		ft_lstclear(&stack_b.first_node);
	if (operation)
		free(operation);
	write(2, "Error\n", 6);
	exit(1);
}

int main(int argc, char *argv[])
{
	t_stack stack_a;
	t_stack stack_b;
	char *operation;

	if (argc == 1)
		return (3);
	initialize_stacks_and_operation(&stack_a, &stack_b, &operation);
	if (!parse(argc, argv, &stack_a))
		free_and_exit(stack_a, stack_b, operation);
	if (!read_operation(&operation))
		free_and_exit(stack_a, stack_b, operation);
	while (operation)
	{
		if (!is_operation(operation))
			free_and_exit(stack_a, stack_b, operation);
		execute_operation(&stack_a, &stack_b, operation);
		free(operation);
		operation = NULL;
		if (!read_operation(&operation))
			free_and_exit(stack_a, stack_b, operation);
		if (!operation)
			break ;
	}
	if (is_sorted(stack_a) && stack_b.first_node == NULL)
        write(1, "OK\n", 3);
  	else
		write(1, "KO\n", 3);
	ft_lstclear(&stack_a.first_node);
	if (stack_b.first_node)
			ft_lstclear(&stack_b.first_node);
	return (0);
}
