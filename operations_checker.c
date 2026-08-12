#include "push_swap.h"
#include <stdarg.h>
#include <stdio.h>

t_stack create_stack(int n, ...)
{
	int i;
	int number;
	t_list *head;
	t_stack stack;
	va_list numbers;

    va_start(numbers, n);
	stack.size = n;
	head = NULL;
	i = 0;
	while (i < n)
	{
		number = va_arg(numbers, int);
		ft_lstadd_back(&head, ft_lstnew(number));
		i++;
	}
	stack.first_node = head;
	stack.last_node = ft_lstlast(head);
	return (stack);
}

void display_stack(t_list *tab)
{
	t_list *node;

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

int main(void)
{
	t_stack stack_a = create_stack(7, 1,2,3,4,5,6,7);
	t_stack stack_b = create_stack(0);
	int counter = 0;

	medium_sort(&stack_a, &stack_b, &counter);
	printf("stack a\n");
	display_stack((stack_a.first_node));
	printf("%i ilosc ruchow", counter);
	return (0);
}