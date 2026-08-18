#include "push_swap.h"

static int	swap_stack(t_stack *stack)
{
    t_list	*first;
    t_list	*second;

    if (stack->size < 2)
        return (0);
    first = stack->first_node;
    second = first->next;
    first->next = second->next;
    if (second->next)
        second->next->prev = first;
    else
        stack->last_node = first;
    second->next = first;
    second->prev = NULL;
    first->prev = second;
    stack->first_node = second;
    return (1);
}

void	sa(t_stack *a, t_ops *ops, int is_bench)
{
    if (!swap_stack(a))
        return ;
    if (is_bench)
        ops->use_sa++;
    write(1, "sa\n", 3);
}

void	sb(t_stack *b, t_ops *ops, int is_bench)
{
    if (!swap_stack(b))
        return ;
    if (is_bench)
        ops->use_sb++;
    write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b, t_ops *ops, int is_bench)
{
    int	a_changed;
    int	b_changed;

    a_changed = swap_stack(a);
    b_changed = swap_stack(b);
    if (!a_changed && !b_changed)
        return ;
    if (is_bench)
        ops->use_ss++;
    write(1, "ss\n", 3);
}