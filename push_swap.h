#include <stdlib.h>

typedef struct s_list
{
	int				number;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_stack
{
	t_list	*first_node;
	t_list	*last_node;
	int		size;
}	t_stack;

void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	simple_sort(t_stack *stack_a, t_stack *stack_b);
t_list	*ft_lstnew(int number);
int		t_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack);
void	sort(t_stack *stack_a, t_stack *stack_b);
void	put_to_stack_b(t_stack *stack_a, t_stack *stack_b, t_list *node_a);
void	put_to_stack_a(t_stack *stack_a, t_stack *stack_b);
