#include "push_swap.h"

float compute_disorder(t_stack stack_a)
{
    int mistakes;
    int total_pairs;
    t_list *node;
    t_list *tmp;

    mistakes = 0;
    node = stack_a.first_node;
    tmp = NULL;
    while (node)
    {
        tmp = node->next;
        while (tmp)
        {
            if(node->number > tmp->number)
                mistakes++;
            tmp = tmp->next;
        }
        node = node->next;
    }
    total_pairs = stack_a.size * (stack_a.size - 1) / 2;
    if (total_pairs == 0)
        return (0.0f);
    return ((float)mistakes / (float)total_pairs);
}