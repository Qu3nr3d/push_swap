#include "push_swap.h"

float compute_disorder(t_stack *a)
{
    int mistakes = 0;
    int total_pairs = 0;
    int i = 0;
    int j = 0;
    while(i < a->size)
    {
        j = i + 1;
        while(j < a->size - 1)
        {
            total_pairs += 1;
            if(a->first_node->number > a->first_node->next->number)
                mistakes += 1;
            j++
        }
        i++;
    }
    return (mistakes / total pairs);
}