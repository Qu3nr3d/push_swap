#include "push_swap.h"

t_stack *create_stack(int n, ...)
{
	int i;
	int number;
	t_list *head;
	t_stack *stack;
	va_list numbers;

    va_start(numbers, n);
	stack = calloc(1, sizeof(t_stack));
	stack->size = n;
	head = ft_lstnew(&number);
	stack->first_node = head;
	i = 0;
	while (i < n)
	{
		number = va_arg(numbers, int);
		ft_lstadd_back(&head, ft_lstnew(&number));
		printf("%d\n", *(int*)(head->content));
		i++;
	}
	stack->last_node = ft_lstlast(head);
	return (stack);
}

void display_stack(t_list *tab)
{
	t_list *node;
	int* number;

	printf("%d\n", *(int*)(tab->content));
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
	/*
	int n = 6;
	t_list *head = ft_lstnew(&n);
	int n1 = 7;
	int n2 = 8;
	int n3 = 9;
	ft_lstadd_back(&head, ft_lstnew(&n1));
	ft_lstadd_back(&head, ft_lstnew(&n2));
	ft_lstadd_back(&head, ft_lstnew(&n3));
	display_stack(head);
	*/

	t_stack *stack_a = create_stack(5, 1, 2, 3, 4, 5);
	display_stack((stack_a->first_node));
	return (0);
}