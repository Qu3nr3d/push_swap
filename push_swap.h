#ifndef "PUSH_SWAP_H"
# define "PUSH_SWAP_H"

#include <stdlib.h>

typedef struct s_list
{
	int				number;
	struct s_list	*next;
	struct s_list	*prev;
	int				index;
}	t_list;

typedef struct s_stack
{
	t_list	*first_node;
	t_list	*last_node;
	int		size;
}	t_stack;

typedef struct s_operations
{
	int use_pa = 0;
	int use_pb = 0;
	int use_sa = 0;
	int use_sb = 0;
	int use_ss = 0;
	int use_ra = 0;
	int use_rb = 0;
	int use_rr = 0;
	int use_rra = 0;
	int use_rrb = 0;
	int use_rrr = 0;
} t_operations;

void	sa(t_stack *stack, int *counter);
void	sb(t_stack *stack, int *counter);
void	ss(t_stack *stack, int *counter);
void	pa(t_stack *stack_a, t_stack *stack_b, int *counter);
void	pb(t_stack *stack_a, t_stack *stack_b, int *counter);
void	simple_sort(t_stack *stack_a, t_stack *stack_b);
t_list	*ft_lstnew(int number);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ra(t_stack *stack, int *counter);
void	rb(t_stack *stack, int *counter);
void	rr(t_stack *stack, int *counter);
void	rra(t_stack *stack, int *counter);
void	rrb(t_stack *stack, int *counter);
void	rrr(t_stack *stack, int *counter);
void	sort(t_stack *stack_a, t_stack *stack_b);
void	put_to_stack_b(t_stack *stack_a, t_stack *stack_b, t_list *node_a);
void	put_to_stack_a(t_stack *stack_a, t_stack *stack_b);
void medium_sort(t_stack *stack_a, t_stack *stack_b, int *counter);

#endif