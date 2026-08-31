/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacpere <akacpere@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 19:39:59 by akacpere          #+#    #+#             */
/*   Updated: 2026/07/09 16:54:18 by akacpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!little[0])
		return ((char *) big);
	while (i != len && big[i])
	{
		if (big[i] == little[j])
		{
			while (big[i + j] == little[j] && (i + j) != len)
			{
				j++;
				if (!little[j])
					return ((char *)(big + i));
			}
			j = 0;
		}
		i++;
	}
	return (NULL);
}
