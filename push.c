#include "push_swap.h"

void pa(t_stack *a, t_stack *b, t_ops *ops, int is_bench)
{
    t_list *p;
    if (b->size == 0)
        return ;
    p = b->first_node;
    b->first_node = p->next;
    if (b->first_node != NULL)
        b->first_node->prev = NULL;
    else
        b->last_node = NULL;
    p->next = a->first_node;
    p->prev = NULL;
    if (a->first_node != NULL)
        a->first_node->prev = p;
    else
        a->last_node = p;
    a->first_node = p;
    a->size++;
    b->size--;
    if (is_bench)
        ops->use_pa++;
    write(1, "pa\n", 3);
}

void pb(t_stack *a, t_stack *b, t_ops *ops, int is_bench)
{
    t_list *p;
    if (a->size == 0)
        return ;
    p = a->first_node;
    a->first_node = p->next;
    if (a->first_node != NULL)
        a->first_node->prev = NULL;
    else
        a->last_node = NULL;
    p->next = b->first_node;
    p->prev = NULL;
    if (b->first_node != NULL)
        b->first_node->prev = p;
    else
        b->last_node = p;
    b->first_node = p;
    b->size++;
    a->size--;
    if (is_bench)
        ops->use_pb++;
    write(1, "pb\n", 3);

}
