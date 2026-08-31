/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacpere <akacpere@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 15:46:16 by akacpere          #+#    #+#             */
/*   Updated: 2026/07/09 18:06:54 by akacpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dest;
	unsigned char	*sourc;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	dest = (unsigned char *) dst;
	sourc = (unsigned char *) src;
	i = 0;
	while (i != n)
	{
		dest[i] = sourc[i];
		i++;
	}
	return (dst);
}
