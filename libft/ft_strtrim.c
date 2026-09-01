/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacpere <akacpere@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 14:21:02 by akacpere          #+#    #+#             */
/*   Updated: 2026/07/08 21:39:21 by akacpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	is_in_set(char const *set, char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (is_in_set(set, s1[i]) && s1[i])
		i++;
	start = i;
	i = 0;
	while (is_in_set(set, s1[ft_strlen(s1) - i - 1]) && s1[i])
		i++;
	end = ft_strlen(s1) - i;
	if (start > end)
		return (ft_strdup(""));
	str = ft_calloc(1, end - start + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1 + start, end - start + 1);
	return (str);
}
