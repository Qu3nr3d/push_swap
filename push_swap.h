#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# define IS_FLAG(x) (!ft_strcmp(x, "--simple") || !ft_strcmp(x, "--medium") || \
                    !ft_strcmp(x, "--complex") || !ft_strcmp(x, "--adaptive") || \
                    !ft_strcmp(x, "--bench"))

if (IS_FLAG(argv[1])) 
{
    i++;
    flag = 1;
}

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
	int use_pa;
	int use_pb;
	int use_sa;
	int use_sb;
	int use_ss;
	int use_ra;
	int use_rb;
	int use_rr;
	int use_rra;
	int use_rrb;
	int use_rrr;
} t_operations;

void	sa(t_stack *stack, t_operations *operations);
void	sb(t_stack *stack, t_operations *operations);
void	ss(t_stack *stack, t_operations *operations);
void	pa(t_stack *stack_a, t_stack *stack_b, t_operations *operations);
void	pb(t_stack *stack_a, t_stack *stack_b, t_operations *operations);
void	simple_sort(t_stack *stack_a, t_stack *stack_b, t_operations *operations);
t_list	*ft_lstnew(int number);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ra(t_stack *stack, t_operations *operations);
void	rb(t_stack *stack, t_operations *operations);
void	rr(t_stack *stack_a, t_stack *stack_b, t_operations *operations);
void	rra(t_stack *stack, t_operations *operations);
void	rrb(t_stack *stack, t_operations *operations);
void rrr(t_stack *stack_a, t_stack *stack_b, t_operations *operations);
void	sort(t_stack *stack_a, t_stack *stack_b);
void	put_to_stack_b(t_stack *stack_a, t_stack *stack_b, t_list *node_a);
void	put_to_stack_a(t_stack *stack_a, t_stack *stack_b);
void medium_sort(t_stack *stack_a, t_stack *stack_b, t_operations *operations);
float compute_disorder(t_stack *a);
void strategy(char *str, t_stack *stack_a, t_stack *stack_b, t_operations *operations);
void benchmark(char *str, t_stack *stack_a, t_stack *stack_b, t_operations *operations);
int	ft_strcmp(char *s1, char *s2);

#endif