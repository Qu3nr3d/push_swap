/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacpere <akacpere@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 17:57:03 by akacpere          #+#    #+#             */
/*   Updated: 2026/07/09 17:18:52 by akacpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*dest;
	unsigned char	*sourc;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	dest = dst;
	sourc = (void *) src;
	i = 0;
	while (i != n)
	{
		if (dest > sourc)
			dest[n - i - 1] = sourc[n - i - 1];
		else
			dest[i] = sourc[i];
		i++;
	}
	return (dst);
}
