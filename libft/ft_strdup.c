/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacpere <akacpere@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 18:30:03 by akacpere          #+#    #+#             */
/*   Updated: 2026/07/08 20:56:29 by akacpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s);

char	*ft_strdup(const char *s)
{
	size_t	size;
	size_t	i;
	char	*str;

	size = ft_strlen(s) + 1;
	i = 0;
	str = malloc(size * sizeof(char));
	if (str == 0)
		return (0);
	while (i != size)
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}
