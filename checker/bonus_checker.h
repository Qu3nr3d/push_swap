/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacpere <akacpere@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 19:15:45 by akacpere          #+#    #+#             */
/*   Updated: 2026/08/28 19:17:40 by akacpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <stddef.h>
# include <stdint.h>

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

void	initialize_stacks_and_operation(t_stack *a, t_stack *b, char **opr);
bool	parse(int argc, char *args[], t_stack *stack_a);
char	*read_operation(t_stacks s);
t_list	*ft_lstnew(int number);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
bool	is_number(char *str);
int		ft_atoi(const char *nptr, int *error);
void	ft_bzero(void *ptr, size_t n);
void	*ft_calloc(size_t n, size_t size);
size_t	ft_strlen(const char *s);
bool	is_operation(char *s);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	execute_operation(t_stack *a, t_stack *b, char *s);
int		is_sorted(t_stack a);
bool	str_is_equal(char *s1, char *s2);
void	*ft_realloc(void *ptr1, int prev_size, int new_size);
char	*ft_strdup(const char *s);
bool	is_newline(char *s);
void	free_stacks(t_stack a, t_stack b);
void	free_stacks_and_exit(t_stack a, t_stack b);
bool	append(t_opr *opr, char *str);

#endif