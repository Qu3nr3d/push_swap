#include "push_swap.h"

static size_t	nbr_len(int n)
{
	size_t	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

// trzbea przepisac aby bylo mniej linijek
char	*ft_itoa(int n)
{
	int		i;
	char	digit;
	char	*str;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = nbr_len(n);
	str = malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	digit = 0;
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	str[i--] = '\0';
	while (n > 0)
	{
		digit = (char){n % 10 + 48};
		n /= 10;
		str[i] = digit;
		i--;
	}
	return (str);
}
