#include "push_swap.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int is_number(char *n)
{
	while (*n)
	{
		if (!ft_isdigit(*n))
			return (0);
		n++;
	}
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int	ret;
	int	sign;

	ret = 0;
	sign = 1;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		ret *= 10;
		ret += (int){*nptr - '0'};
		nptr++;
	}
	return (sign * ret);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
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
