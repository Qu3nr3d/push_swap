/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_read_operations_utils_1.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacpere <akacpere@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 20:41:58 by akacpere          #+#    #+#             */
/*   Updated: 2026/08/28 21:14:02 by akacpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_checker.h"

void	*ft_realloc(void *ptr1, int prev_size, int new_size)
{
	void			*ptr2;
	unsigned char	*pointer1;
	unsigned char	*pointer2;
	int				i;
	int				size;

	i = 0;
	ptr2 = ft_calloc(new_size, sizeof(char));
	if (!ptr2)
		return (NULL);
	pointer1 = (unsigned char *) ptr1;
	pointer2 = (unsigned char *) ptr2;
	if (prev_size < new_size)
		size = prev_size;
	else
		size = new_size;
	while (i < size)
	{
		pointer2[i] = pointer1[i];
		i++;
	}
	free(ptr1);
	return (ptr2);
}

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

bool	is_newline(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (true);
		i++;
	}
	return (false);
}
