/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacpere <akacpere@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 16:44:41 by kgirczyc          #+#    #+#             */
/*   Updated: 2026/08/31 15:35:34 by akacpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ops	initialize_ops(void)
{
	t_ops	ops;

	ops.use_pa = 0;
	ops.use_pb = 0;
	ops.use_sa = 0;
	ops.use_sb = 0;
	ops.use_ss = 0;
	ops.use_ra = 0;
	ops.use_rb = 0;
	ops.use_rr = 0;
	ops.use_rra = 0;
	ops.use_rrb = 0;
	ops.use_rrr = 0;
	return (ops);
}

bool	is_sorted(t_stack a)
{
	t_doubly_list	*node;

	node = a.first_node;
	while (node->next)
	{
		if (node->number > node->next->number)
			return (false);
		node = node->next;
	}
	return (true);
}



void	*ft_realloc(void *ptr1, int prev_size, int new_size)
{
	void			*ptr2;
	unsigned char	*pointer1;
	unsigned char	*pointer2;
	int				i;
	int				size;

	i = 0;
	ptr2 = ft_calloc(new_size, sizeof(char));
	if (!ptr2)
		return (NULL);
	pointer1 = (unsigned char *) ptr1;
	pointer2 = (unsigned char *) ptr2;
	if (prev_size < new_size)
		size = prev_size;
	else
		size = new_size;
	while (i < size)
	{
		pointer2[i] = pointer1[i];
		i++;
	}
	free(ptr1);
	return (ptr2);
}

bool	is_newline(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (true);
		i++;
	}
	return (false);
}

