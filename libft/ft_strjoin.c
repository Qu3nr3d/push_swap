/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacpere <akacpere@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 14:22:26 by akacpere          #+#    #+#             */
/*   Updated: 2026/07/02 14:59:18 by akacpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	char	*str;

	if (s1 == 0 || s2 == 0)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	str = malloc((len + 1) * sizeof(char));
	if (str == 0)
		return (0);
	while (*s1)
	{
		str[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		str[i] = *s2;
		i++;
		s2++;
	}
	str[i] = '\0';
	return (str);
}
