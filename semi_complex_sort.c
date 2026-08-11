#include "push_swap.h"

int	ft_sqrt(int nb)
{
    int i;

    if (nb <= 0)
        return (0);
    i = 1;
    while (i <= nb / i)
        i++;
    return (i - 1);
}

void bubble_sort(t_stack *stack) {
    int i;
    int j;
    int swapped;

    i = 0;
    while (i < stack->size - 1) {
        swapped = 0;
        j = 0;
        while (j < stack->size -1) {
            if (stack->first_node->number < stack->first_node->next->number) {
                sb(stack);
                swapped = 1;
            }
            rb(stack);
            j++;
        }
        while (j-- > 0)
            rrb(stack);
        if (!swapped)
            break;
        i++;
    }
}

void medium_sort(t_stack *stack_a, t_stack *stack_b) {
    int block_size = ft_sqrt(stack_a->size);
    int i = 0;
    int remaining = stack_a->size;
    int current_block_size;
    while (remaining > 0) {
        if (remaining < block_size)
            current_block_size = remaining;
        else
            current_block_size = block_size;
        while (current_block_size > i++)
            pb(stack_a, stack_b);
        bubble_sort(stack_b);
        i = 0;
        while (i++ < current_block_size)
            pa(stack_a, stack_b);
        i = 0;
        while (i++ < current_block_size)
            ra(stack_a);
        remaining -= current_block_size;
        i = 0;
    }
}