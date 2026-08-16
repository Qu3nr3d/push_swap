#include "push_swap.h"

float compute_disorder(t_stack stack_a)
{
    int mistakes;
    int total_pairs;
    t_list *node;
    t_list *tmp;

    mistakes = 0;
    total_pairs = 0;
    node = stack_a.first_node;
    tmp = NULL;
    while (node)
    {
        tmp = node->next;
        while (node->next)
        {
            total_pairs += 1;
            if(node->number > node->next->number)
                mistakes += 1;
            node = node->next;
        }
        node = tmp;
    }
    return (mistakes / total_pairs);
}
/*
void strategy(char *str, t_stack *stack_a, t_stack *stack_b, t_operations *operations)
{
    float disorder;

    if(!ft_strcmp("--simple", str))
        simple_sort(stack_a, stack_b, operations);
    else if (!ft_strcmp("--medium", str))
        medium_sort(stack_a, stack_b, operations);
    // else if (!ft_strcmp("--complex", str))
    //     complex_sort(stack_a, stack_b, operations);
    else if (!ft_strcmp("--adaptive", str))
    {
        disorder = compute_disorder(stack_a);
        if(disorder < 0.2)
            simple_sort(stack_a, stack_b, operations);
        else if (disorder < 0.5)
            medium_sort(stack_a, stack_b, operations);
        // else
        //     complex_sort(stack_a, stack_b, operations);
    }
}

void benchmark(char *str, t_stack *stack_a, t_stack *stack_b, t_operations *operations)
{
    float disorder = compute_disorder(stack_a);
    if(disorder)
    {
        write(1,"1",1);
    }
    strategy(str, stack_a, stack_b, operations);
}
*/