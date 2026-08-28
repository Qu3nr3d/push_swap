/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker_utils_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacpere <akacpere@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 20:36:52 by akacpere          #+#    #+#             */
/*   Updated: 2026/08/28 21:13:33 by akacpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_checker.h"

bool	is_number(char *str)
{
	int	i;

	if (!str || !str[0])
		return (false);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (false);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

int	ft_atoi(const char *nptr, int *error)
{
	long long	number;
	int			sign;

	number = 0;
	sign = 1;
	*error = 0;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		number = number * 10 + (*nptr - '0');
		if (number * sign > 2147483647LL || number * sign < -2147483648LL)
			return (*error = 1, 0);
		nptr++;
	}
	return ((int)number * sign);
}

void	ft_bzero(void *ptr, size_t n)
{
	unsigned char	*pointer;
	size_t			i;

	i = 0;
	pointer = (unsigned char *)ptr;
	while (i < n)
		pointer[i++] = '\0';
}

void	*ft_calloc(size_t n, size_t size)
{
	void	*ptr;

	if (n * size > SIZE_MAX)
		return (NULL);
	if (n == 0 || size == 0)
		return (NULL);
	ptr = malloc(n * size);
	ft_bzero(ptr, n * size);
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
