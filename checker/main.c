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

void put_error(t_stack *stack)
{
	ft_lstclear(&stack->first_node);
	write(2, "Error\n", 6);
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
		return(put_error(&stack_a), 2);
	display_stack(stack_a.first_node);
	//int fd = open("steps.txt", O_RDONLY);
	operation = read_operation();
	//printf("operation: %s\n", operation);
	if (!operation)
		return(put_error(&stack_a), 1);
	while (operation)
	{
		//printf("operation: %s\n", operation);
		if (!is_operation(operation))
		{
			printf("operation: %s\n", operation);
			printf("goes here\n");
			return(put_error(&stack_a), 1);
		}
		execute_operation(&stack_a, &stack_b, operation);
		 operation = read_operation();
		// if (str_is_equal(operation, ""))
		// 	printf("Yeah, it gives back an empty string.\n");
	}
	printf("\n");
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
    //jak nie wyjdzie z malloca albo zly inout to error trzeba wypisac tutaj
    //get next line z readem ze stdinput
//     operation = get_next_line()
//     while(operation)
//     {
//         execute_operation(&stack_a, &stack_b);
//         operation = get_next_line();
//        //sprawdzic czy operacja jest okej, jak nie to error
//     }