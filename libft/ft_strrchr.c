/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacpere <akacpere@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 14:31:28 by akacpere          #+#    #+#             */
/*   Updated: 2026/07/09 17:17:09 by akacpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	if (c == '\0')
		return ((char *)(s + len));
	while (len)
	{
		if (s[len - 1] == (char) c)
			return ((char *)(s + len - 1));
		len--;
	}
	return (0);
}
