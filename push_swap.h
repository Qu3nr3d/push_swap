#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

typedef struct s_operations
{
	int	use_pa;
	int	use_pb;
	int	use_sa;
	int	use_sb;
	int	use_ss;
	int	use_ra;
	int	use_rb;
	int	use_rr;
	int	use_rra;
	int	use_rrb;
	int	use_rrr;
} t_operations;

typedef struct s_metrics
{
	float			disorder;
	char			*strategy;
	int				total_ops;
	t_operations	operations;
} t_metrics;

typedef struct s_flags
{
	int	is_bench;
	int	is_simple;
	int	is_medium;
	int	is_complex;
} t_flags;

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

void	sa(t_stack *stack, t_operations *operations);
void	sb(t_stack *stack, t_operations *operations);
void	ss(t_stack *stack_a, t_stack *stack_b, t_operations *operations);
void	pa(t_stack *stack_a, t_stack *stack_b, t_operations *operations);
void	pb(t_stack *stack_a, t_stack *stack_b, t_operations *operations);
void	ra(t_stack *stack, t_operations *operations);
void	rb(t_stack *stack, t_operations *operations);
void	rr(t_stack *stack_a, t_stack *stack_b, t_operations *operations);
void	rra(t_stack *stack, t_operations *operations);
void	rrb(t_stack *stack, t_operations *operations);
void    rrr(t_stack *stack_a, t_stack *stack_b, t_operations *operations);
t_list	*ft_lstnew(int number);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	simple_sort(t_stack *stack_a, t_stack *stack_b, t_operations *operations);
void    medium_sort(t_stack *stack_a, t_stack *stack_b, t_operations *operations);
void	complex_sort(t_stack *stack_a, t_stack *stack_b, t_operations *operations);
void	put_to_stack_b(t_stack *stack_a, t_stack *stack_b, t_list *node_a, t_operations *operations);
void	put_to_stack_a(t_stack *stack_a, t_stack *stack_b, t_operations *operations);
int     parse(int argc, char *args[], t_stack *stack_a);
void    initialize_flags(int number_of_args, char *args[], t_flags *flags);
int     is_number(char *n);
void    initialize_stacks (t_stack *stack_a, t_stack *stack_b);
int	    ft_atoi(const char *nptr, int *number);
char	*ft_strdup(const char *s);
int	    is_flag(char *str);
float   compute_disorder(t_stack stack_a);
void    initialize_metrics(t_metrics *metrics, t_flags flags, t_stack stack_a);
t_operations initialize_operations();

#endif