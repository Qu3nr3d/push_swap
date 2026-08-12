#include "push_swap.h"

void sa(t_stack *stack, int *counter) {
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
    (*counter)++;
}

void sb(t_stack *stack, int *counter) {
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
    (*counter)++;
}

void ss(t_stack *stack, int *counter)
{
    sa(stack, counter);
    sb(stack, counter);
}