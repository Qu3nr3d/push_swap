/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacpere <akacpere@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 12:32:17 by akacpere          #+#    #+#             */
/*   Updated: 2026/07/08 20:14:54 by akacpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	str_len;
	size_t	i;

	if (s == 0)
		return (0);
	str_len = ft_strlen(s);
	if (start > (unsigned int) str_len)
		return (ft_strdup(""));
	str_len = ft_strlen(s);
	if (start + len > str_len)
		substr = malloc(((unsigned int) str_len - start + 1) * sizeof(char));
	else
		substr = malloc((len + 1) * sizeof(char));
	if (substr == 0)
		return (0);
	i = 0;
	while (i != len && s[start])
	{
		substr[i] = s[start];
		start++;
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
