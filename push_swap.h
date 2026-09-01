/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacpere <akacpere@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 17:04:27 by kgirczyc          #+#    #+#             */
/*   Updated: 2026/09/01 14:51:18 by akacpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include "libft/libft.h"

typedef struct s_pass
{
	int	processed;
	int	pair;
	int	right_size;
	int	i;
}	t_pass;

typedef struct s_merge
{
	int	left;
	int	right;
	int	ascending;
}	t_merge;

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
}	t_ops;

typedef struct s_metrics
{
	float			disorder;
	char			*strategy;
	int				total_ops;
	t_ops			ops;
}	t_metrics;

typedef struct s_flags
{
	int	is_bench;
	int	is_simple;
	int	is_medium;
	int	is_complex;
	int	is_adaptive;
}	t_flags;

typedef struct s_doubly_list
{
	int						number;
	struct s_doubly_list	*next;
	struct s_doubly_list	*prev;
	int						index;
}	t_doubly_list;

typedef struct s_stack
{
	t_doubly_list	*first_node;
	t_doubly_list	*last_node;
	int				size;
}	t_stack;

typedef struct s_stacks
{
	t_stack	stack_a;
	t_stack	stack_b;
}	t_stacks;

typedef struct s_opr
{
	char	*opr;
	int		size;
	int		space;
}	t_opr;

typedef struct s_str_ops
{
	char	*str_total_ops;
	char	*str_pa;
	char	*str_pb;
	char	*str_sa;
	char	*str_sb;
	char	*str_ss;
	char	*str_ra;
	char	*str_rb;
	char	*str_rr;
	char	*str_rra;
	char	*str_rrb;
	char	*str_rrr;
}	t_str_ops;

typedef struct s_medium
{
	t_stack	*a;
	t_stack	*b;
	t_ops	*ops;
	int		is_bench;
}	t_medium;

bool			init_flags(int argc, char *args[], t_flags *flags);
t_ops			init_ops(void);
void			init_stacks(t_stack *stack_a, t_stack *stack_b);
bool			parse(int argc, char *args[], t_stack *stack_a);
bool			init_metrics(t_metrics *metrics, t_flags flags, t_stack a);
float			compute_disorder(t_stack stack_a);
void			choose_algorithm(t_flags *flags, float disorder);
void			update_metrics(t_metrics *metrics);
bool			print_benchmark(t_metrics metrics);
void			simple_sort(t_stack *a, t_stack *b, t_ops *ops, int is_bench);
void			medium_sort(t_stack *a, t_stack *b, t_ops *ops, int is_bench);
void			complex_sort(t_stack *a, t_stack *b, t_ops *ops, int is_bench);
int				swap_stack(t_stack *stack);
int				push_stack(t_stack *pushed_to, t_stack *pushed_from);
int				rotate_stack(t_stack *stack);
int				reverse_rotate_stack(t_stack *stack);
void			sa(t_stack *a, t_ops *ops, int is_bench);
void			sb(t_stack *b, t_ops *ops, int is_bench);
void			ss(t_stack *a, t_stack *b, t_ops *ops, int is_bench);
void			pa(t_stack *a, t_stack *b, t_ops *ops, int is_bench);
void			pb(t_stack *a, t_stack *b, t_ops *ops, int is_bench);
void			ra(t_stack *a, t_ops *ops, int is_bench);
void			rb(t_stack *b, t_ops *ops, int is_bench);
void			rr(t_stack *a, t_stack *b, t_ops *ops, int is_bench);
void			rra(t_stack *a, t_ops *ops, int is_bench);
void			rrb(t_stack *b, t_ops *ops, int is_bench);
void			rrr(t_stack *a, t_stack *b, t_ops *ops, int is_bench);
t_doubly_list	*lstnew(int number);
int				lstsize(t_doubly_list *lst);
t_doubly_list	*lstlast(t_doubly_list *lst);
void			lstclear(t_doubly_list **lst);
void			lstadd_back(t_doubly_list **lst, t_doubly_list *new);
int				get_orientation(int index, int level);
void			sort_block(t_medium *m, int size, int ascending);
void			merge_pass(t_medium *m, int total, int size, int level);
void			print_on_stderr(char *s);
bool			str_is_equal(char *s1, char *s2);
int				ft_atoi_with_error(const char *nptr, int *error);
long			round_float(double n);
int				get_float_len(long x, int neg);
bool			is_sorted(t_stack a);
int				find_max_number(t_stack stack);
int				find_min_number(t_stack stack);
bool			is_duplicate(t_stack *stack, int number);
bool			is_num_arr(char *s);
bool			is_number(char *n);
bool			is_flag(char *str);
char			*float_to_str(double n);
char			*read_operation(t_stacks s);
void			*ft_realloc(void *ptr1, int prev_size, int new_size);
bool			is_newline(char *s);
void			free_stacks(t_stack a, t_stack b);
void			free_stacks_and_exit(t_stack a, t_stack b);
bool			is_operation(char *s);
void			execute_operation_1(t_stack *a, t_stack *b, char *s);
void			execute_operation_2(t_stack *a, t_stack *b, char *s);

#endif
