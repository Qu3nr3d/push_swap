#include "push_swap.h"

void simple_sort_inside(t_list *helper, t_list *p, int *min_i, int *curr_i) {
    while (helper)
    {
        if (helper->number < p->number)
        {
            p = helper;
            *min_i = *curr_i;
        }
        helper = helper->next;
        (*curr_i)++;
    }
}

void simple_sort(t_stack *stack_a, t_stack *stack_b)
{
    int min_i;
    int curr_i;
    t_node *p;
    t_node *helper;

    while (stack_a->first_node)
    {
        min_i = 0;
        curr_i = 1;
        p = stack_a->first_node;
        helper = stack_a->first_node->next;
        simple_sort_inside(helper, p, &min_i, &curr_i);
        if (min_i <= curr_i / 2) {
            while (min_i-- > 0)
                ra(stack_a);
        }
        else
            while (curr_i - min_i++ > 0)
                rra(stack_a);
        pb(stack_a, stack_b);
    }
    while (stack_b->first_node)
        pa(stack_a, stack_b);
}