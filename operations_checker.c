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
	t_stack stack_a = create_stack(3, 2,3,4);
	t_stack stack_b = create_stack(3, 5,6,7);
	/*
	// printf("Stack a: rotate...\n");
	// display_stack((stack_a->first_node));
	// printf("%p\n", stack_a->first_node->prev);
	// ra(&stack_a->first_node, &stack_a->last_node);
	// display_stack((stack_a->first_node));
	// printf("%p\n", stack_a->first_node->prev);
	// printf("Stack b: reverse rotate...\n");
	// display_stack((stack_b->first_node));
	// rrb(&stack_b->first_node, &stack_b->last_node);
	// display_stack((stack_b->first_node));
	
	// printf("Stack a: swap...\n");
	// display_stack((stack_a->first_node));
	// sa(stack_a->first_node, stack_a->size);
	// display_stack((stack_a->first_node));
	// */
	// printf("Stack a\n");
	// display_stack((stack_a.first_node));
	// printf("Stack b\n");
	// display_stack((stack_b.first_node));
	// sort(&stack_a, &stack_b);
	// printf("after sorting...\n");
	// printf("Stack a\n");
	// display_stack((stack_a.first_node));
	// printf("Stack b\n");
	// display_stack((stack_b.first_node));
	// /*
	// printf("stack a first_node: %d\n", stack_a.first_node->number);
	// printf("stack a last_node: %d\n", stack_a.last_node->number);
	// printf("stack b first_node: %d\n", stack_b.first_node->number);
	// printf("stack b last_node: %d\n", stack_b.last_node->number);
	// printf("Stack a\n");
	// for (t_list *first = stack_a.first_node; first != NULL; first = first->next)
	// 	printf("%d\n", first->number);
	// printf("\n");
	// for (t_list *last = stack_a.last_node; last != NULL; last = last->prev)
	// 	printf("%d\n", last->number);
	// printf("Stack b\n");
	// for (t_list *first = stack_b.first_node; first != NULL; first = first->next)
	// 	printf("%d\n", first->number);
	// printf("\n");
	// for (t_list *last = stack_b.last_node; last != NULL; last = last->prev)
	// 	printf("%d\n", last->number);
	// */

	// printf("before connecting...\n");
	// put_to_stack_a(&stack_a, &stack_b);

	// printf("after connecting...\n");
	// printf("Stack a\n");
	// display_stack((stack_a.first_node));
	// printf("Stack b\n");
	// display_stack((stack_b.first_node));

	// pa(&stack_a, &stack_b);
	// printf("stack a\n");
	// display_stack((stack_a.first_node));
	// printf("Stack b\n");
	// display_stack((stack_b.first_node));

	rra(&stack_a);
	printf("stack a\n");
	display_stack((stack_a.first_node));

	rrb(&stack_b);
	printf("stack a\n");
	display_stack((stack_b.first_node));

	return (0);
}