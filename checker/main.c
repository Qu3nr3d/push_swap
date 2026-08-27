#include "checker.h"
#include <stdio.h>
#include <fcntl.h>

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

static void free_and_exit(t_stack stack_a, t_stack stack_b)
{
	if (stack_a.first_node)
		ft_lstclear(&stack_a.first_node);
	if (stack_b.first_node)
		ft_lstclear(&stack_b.first_node);
	write(2, "Error\n", 6);
	exit(1);
}

static bool is_end_of_stdin(char *s)
{
	if (str_is_equal(s, "\n"))
		return (true);
	return (false);
}

int main(int argc, char *argv[])
{
	t_stack stack_a;
	t_stack stack_b;
	char *operation;

	if (argc == 1)
		return (3);
	initialize_stacks(&stack_a, &stack_b);
	if (!parse(argc, argv, &stack_a))
		free_and_exit(stack_a, stack_b);
	display_stack(stack_a.first_node);
	operation = NULL;
	read_operation(&operation);
	if (!operation)
		free_and_exit(stack_a, stack_b);
	while (operation)
	{
		if (is_end_of_stdin(operation))
			break ;
		if (!is_operation(operation))
			free_and_exit(stack_a, stack_b);
		execute_operation(&stack_a, &stack_b, operation);
		free(operation);
		operation = NULL;
		read_operation(&operation);
		if (!operation)
			free_and_exit(stack_a, stack_b);
	}
	display_stack(stack_a.first_node);
	if (is_sorted(stack_a)  && stack_b.first_node == NULL && stack_b.first_node == NULL)
         printf("OK\n");
  	else
	{
		printf("KO\n");
		return(1);
	}
	return (0);
}
