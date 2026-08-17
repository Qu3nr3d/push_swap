#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

typedef struct s_ops
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
} t_ops;

typedef struct s_metrics
{
	float			disorder;
	char			*strategy;
	int				total_ops;
	t_ops	ops;
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

void	initialize_flags(int number_of_args, char *args[], t_flags *flags);
t_ops	initialize_ops();
void	initialize_stacks (t_stack *stack_a, t_stack *stack_b);
int		parse(int argc, char *args[], t_stack *stack_a);
void	initialize_metrics(t_metrics *metrics, t_flags flags, t_stack stack_a);
float	compute_disorder(t_stack stack_a);
char	*choose_strategy(t_flags flags, float disorder);
void	print_benchmark(t_metrics metrics);
void	sa(t_stack *stack, t_ops *ops);
void	sb(t_stack *stack, t_ops *ops);
void	ss(t_stack *stack_a, t_stack *stack_b, t_ops *ops);
void	pa(t_stack *stack_a, t_stack *stack_b, t_ops *ops);
void	pb(t_stack *stack_a, t_stack *stack_b, t_ops *ops);
void	ra(t_stack *stack, t_ops *ops);
void	rb(t_stack *stack, t_ops *ops);
void	rr(t_stack *stack_a, t_stack *stack_b, t_ops *ops);
void	rra(t_stack *stack, t_ops *ops);
void	rrb(t_stack *stack, t_ops *ops);
void    rrr(t_stack *stack_a, t_stack *stack_b, t_ops *ops);
void	simple_sort(t_stack *stack_a, t_stack *stack_b, t_ops *ops);
void	medium_sort(t_stack *stack_a, t_stack *stack_b, t_ops *ops);
void	complex_sort(t_stack *stack_a, t_stack *stack_b, t_ops *ops);
t_list	*ft_lstnew(int number);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		is_number(char *n);
int		ft_atoi(const char *nptr, int *error);
char	*ft_strdup(const char *s);
char	*ft_itoa(int n);
int		is_flag(char *str);



#endif