/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_for_ARG.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgirczyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 19:27:59 by kgirczyc          #+#    #+#             */
/*   Updated: 2026/08/28 19:28:12 by kgirczyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	min(unsigned int i, unsigned int j)
{
	if (i <= j)
		return (i);
	return (j);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	len_s;
	unsigned int	j;
	size_t			k;
	unsigned int	real_len;
	char			*ptr;	

	len_s = 0;
	j = 0;
	k = 0;
	while (s[len_s])
		len_s++;
	if (len_s < start)
		return (ft_strdup(""));
	real_len = min(len, (len_s - start));
	ptr = (char *)malloc(sizeof(char) * (real_len + 1));
	if (!ptr)
		return (NULL);
	while (s[start + j] && k < real_len)
	{
		ptr[j] = s[start + j];
		j++;
		k++;
	}
	ptr[j] = '\0';
	return (ptr);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	in_set(char c, char const *set)
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

	start = 0;
	end = ft_strlen((char *)s1);
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && in_set(s1[start], set))
		start++;
	while (end > start && in_set(s1[end - 1], set))
		end--;
	return (ft_substr(s1, start, end - start));
}
