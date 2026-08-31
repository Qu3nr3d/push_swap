/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacpere <akacpere@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 13:17:18 by akacpere          #+#    #+#             */
/*   Updated: 2026/07/08 13:17:30 by akacpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*current_node;
	int		len;

	if (!lst)
		return (0);
	current_node = lst;
	len = 0;
	while (current_node)
	{
		current_node = current_node->next;
		len++;
	}
	return (len);
}
