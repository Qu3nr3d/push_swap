#include "push_swap.h"

void sa(t_stack *stack, t_ops *ops) {
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
    ops->use_sa++;
    write(1,"sa\n", 3);
}

void sb(t_stack *stack, t_ops *ops) {
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
    ops->use_sb++;
    write(1,"sa\n", 3);
}

void ss(t_stack *stack, t_ops *ops)
{
    sa(stack, ops);
    sb(stack, ops);
    ops->use_ss++;
    write(1,"sa\n", 3);
}