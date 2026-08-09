#include "push_swap.h"

void sa(t_stack *stack) {
    t_list *first;
    t_list *second;

    if (stack->size < 2)
        return ;
    first = stack->first_node;
    second = stack->first_node->next;
    first->next = second->next;
    if (second->next)
        second->next->prev = first;
    second->next = first;
    second->prev = NULL;
    first->prev = second;
    stack->first_node = second;
}

void sb(t_stack *stack) {
    t_list *first;
    t_list *second;

    if (stack->size < 2)
        return ;
    first = stack->first_node;
    second = stack->first_node->next;
    first->next = second->next;
    if (second->next)
        second->next->prev = first;
    second->next = first;
    second->prev = NULL;
    first->prev = second;
    stack->first_node = second;
}

void ss(t_stack *stack)
{
    sa(stack);
    sb(stack);
}