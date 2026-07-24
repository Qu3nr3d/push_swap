#include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	t_list	*first_node;
	t_list	*last_node;
	int		size;
}	t_stack;

void	sb(t_list *tab, int size);
void	ss(t_list *taba, t_list *tabb, int sizea, int sizeb);
void	pa(t_list **taba, t_list **tabb);
void	pb(t_list **taba, t_list **tabb);
void	simple_sort(t_stack *stack_a, t_stack *stack_b);
t_list	*ft_lstnew(void *content);
int		t_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ra(t_stack *taba);
void	rb(t_stack *tabb);
void	rra(t_stack *taba);
void	rrb(t_stack *tabb);
