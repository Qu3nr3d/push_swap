#include "push_swap.h"
#include <stdarg.h>
#include <stdio.h>

t_stack *create_stack(int n, ...)
{
	int i;
	int *number;
	t_list *head;
	t_stack *stack;
	va_list numbers;

    va_start(numbers, n);
	stack = calloc(1, sizeof(t_stack));
	stack->size = n;
	head = NULL;
	i = 0;
	while (i < n)
	{
		number = calloc(1, sizeof(int));
		*number = va_arg(numbers, int);
		ft_lstadd_back(&head, ft_lstnew(number));
		i++;
	}
	stack->first_node = head;
	stack->last_node = ft_lstlast(head);
	return (stack);
}

void display_stack(t_list *tab)
{
	t_list *node;
	int* number;

	node = tab;
	while (node)
	{
		number = (int*)(node->content);
		printf("| ");
		printf("%d", *number);
		printf(" |");
		node = node->next;
		printf("\n");
	}
	printf("\n");
}

int main(void)
{
	t_stack *stack_a = create_stack(5, 1, 2, 3, 4, 5);
	t_stack *stack_b = create_stack(5, 9, 8, 7, 6, 5);
	printf("Stack a: rotate...\n");
	display_stack((stack_a->first_node));
	ra(stack_a);
	display_stack((stack_a->first_node));
	printf("Stack a: reverse rotate...\n");
	display_stack((stack_b->first_node));
	rra(stack_b);
	display_stack((stack_b->first_node));
	return (0);
}