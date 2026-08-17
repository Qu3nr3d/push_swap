#include "push_swap.h"

void pa(t_stack *stack_a, t_stack *stack_b, t_ops *ops)
{
    t_list *p;
    if (stack_b->size == 0)
        return ;
    p = stack_b->first_node;
    stack_b->first_node = p->next;
    if (stack_b->first_node != NULL)
        stack_b->first_node->prev = NULL;
    else
        stack_b->last_node = NULL;
    p->next = stack_a->first_node;
    p->prev = NULL;
    if (stack_a->first_node != NULL)
        stack_a->first_node->prev = p;
    else
        stack_a->last_node = p;
    stack_a->first_node = p;
    stack_a->size++;
    stack_b->size--;
    ops->use_pa++;
    write(1, "pa\n", 3);
}

void pb(t_stack *stack_a, t_stack *stack_b, t_ops *ops)
{
    t_list *p;
    if (stack_a->size == 0)
        return ;
    p = stack_a->first_node;
    stack_a->first_node = p->next;
    if (stack_a->first_node != NULL)
        stack_a->first_node->prev = NULL;
    else
        stack_a->last_node = NULL;
    p->next = stack_b->first_node;
    p->prev = NULL;
    if (stack_b->first_node != NULL)
        stack_b->first_node->prev = p;
    else
        stack_b->last_node = p;
    stack_b->first_node = p;
    stack_b->size++;
    stack_a->size--;
    ops->use_pb++;
    write(1, "pb\n", 3);

}
