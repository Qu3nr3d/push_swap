
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

void	initialize_stacks(t_stack *stack_a, t_stack *stack_b);
bool	parse(int argc, char *args[], t_stack *stack_a);
bool	read_stdin(char **operation, int fd, bool *is_EOF);
t_list	*ft_lstnew(int number);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
bool	is_number(char *str);
int     ft_atoi(const char *nptr, int *error);
void    *ft_calloc(size_t n, size_t size);
size_t	ft_strlen(const char *s);
