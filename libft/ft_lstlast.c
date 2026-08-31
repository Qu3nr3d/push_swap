/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacpere <akacpere@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 13:29:11 by akacpere          #+#    #+#             */
/*   Updated: 2026/07/08 14:30:49 by akacpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int		len;
	t_list	*last_node;

	if (!lst)
		return (NULL);
	len = ft_lstsize(lst);
	last_node = lst;
	while (len > 1)
	{
		last_node = last_node->next;
		len --;
	}
	return (last_node);
}
