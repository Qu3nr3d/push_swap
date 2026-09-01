/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacpere <akacpere@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 18:14:23 by akacpere          #+#    #+#             */
/*   Updated: 2026/07/08 20:55:59 by akacpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*dest;
	size_t			i;

	dest = (unsigned char *) s;
	i = 0;
	while (i != n)
	{
		dest[i] = (unsigned char) c;
		i++;
	}
	return (s);
}
