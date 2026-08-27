
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

typedef struct s_operation {
	char	*operation;
	int		size;
	int		capacity;
} t_operation;

void	initialize_stacks(t_stack *stack_a, t_stack *stack_b);
bool	parse(int argc, char *args[], t_stack *stack_a);
bool	read_operation(char **opr);
t_list	*ft_lstnew(int number);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
bool	is_number(char *str);
int     ft_atoi(const char *nptr, int *error);
void	ft_bzero(void *ptr, size_t n);
void    *ft_calloc(size_t n, size_t size);
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
void *reallocate(void *ptr1, int prev_size, int new_size);
char	*ft_strdup(const char *s);
bool is_newline(char *s);

