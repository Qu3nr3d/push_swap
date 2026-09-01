/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacpere <akacpere@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 23:39:21 by akacpere          #+#    #+#             */
/*   Updated: 2026/08/31 23:45:53 by akacpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	free_stacks(t_stack a, t_stack b)
{
	if (a.first_node)
		lstclear(&a.first_node);
	if (b.first_node)
		lstclear(&b.first_node);
}

void	free_stacks_and_exit(t_stack a, t_stack b)
{
	free_stacks(a, b);
	write(2, "Error\n", 6);
	exit(1);
}
