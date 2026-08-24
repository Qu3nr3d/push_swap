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

	initialize_stacks(&stack_a, &stack_b);
	if (!parse(argc, argv, &stack_a))
		return(put_error(&stack_a), 2);
	display_stack(stack_a.first_node);
	operation = ft_calloc(5, sizeof(char));
	if (!operation)
		return(put_error(&stack_a), 1);

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
//     if (is_sorted(stack_a)  && stack_b.first_node = NULL && stack_b.last_node = NULL)
//     {
//          printf("OK"\n);
//          return (0);
// }
//   else
// {
//       printf("KO"\n);
//       return(1);
// }
// }