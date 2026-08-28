/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_read_operations_utils_2.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacpere <akacpere@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 19:09:47 by akacpere          #+#    #+#             */
/*   Updated: 2026/08/28 21:14:06 by akacpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_checker.h"

void	free_stacks(t_stack a, t_stack b)
{
	if (a.first_node)
		ft_lstclear(&a.first_node);
	if (b.first_node)
		ft_lstclear(&b.first_node);
}

void	free_stacks_and_exit(t_stack a, t_stack b)
{
	free_stacks(a, b);
	write(2, "Error\n", 6);
	exit(1);
}

bool	append(t_opr *opr, char *str)
{
	int	i;

	i = 0;
	if (!opr->opr)
	{
		opr->opr = ft_calloc(opr->space, sizeof(char));
		if (!opr->opr)
			return (false);
	}
	while (str[i])
	{
		opr->opr[opr->size++] = str[i];
		if (opr->size == opr->space)
		{
			opr->opr = ft_realloc(opr->opr, opr->space, opr->space * 2);
			if (!opr->opr)
				return (false);
			opr->space *= 2;
		}
		if (str[i] == '\n')
			break ;
		i++;
	}
	opr->opr[opr->size] = '\0';
	return (true);
}
