#include "push_swap.h"

float compute_disorder(t_stack *a)
{
    int mistakes = 0;
    int total_pairs = 0;
    int i = 0;
    int j = 0;
    t_list *node;

    node = a->first_node;
    while(i < a->size)
    {
        j = i + 1;
        while(j < a->size - 1)
        {
            total_pairs += 1;
            if(node->number > node->next->number)
                mistakes += 1;
            j++
            node = node->next;
        }
        i++;
        node = a->first_node;
    }
    return (mistakes / total_pairs);
}

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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] - s2[i] != 0)
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}