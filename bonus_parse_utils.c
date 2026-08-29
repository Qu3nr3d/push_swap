/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_parse_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacpere <akacpere@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 18:53:52 by akacpere          #+#    #+#             */
/*   Updated: 2026/08/29 18:57:00 by akacpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_checker.h"

bool	is_duplicate(t_stack *stack, int number)
{
	t_list	*node;

	node = stack->first_node;
	while (node)
	{
		if (node->number == number)
			return (true);
		node = node->next;
	}
	return (false);
}

bool	is_num_arr(char *s)
{
	int	i;

	i = 0;
	if (!s || !s[0])
		return (false);
	while (s[i] && s[i] == ' ')
		i++;
	while (s[i])
	{
		if (s[i] == '-' || s[i] == '+')
			i++;
		if (s[i] && !(s[i] >= '0' && s[i] <= '9'))
			return (false);
		i++;
		while (s[i] && s[i] == ' ')
			i++;
	}
	return (true);
}

bool	is_number(char *str)
{
	int	i;

	if (!str || !str[0])
		return (false);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (false);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}
