#include "libft.h"

char	*ft_itoa(int n)
{
	int		i;
	char	*str;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = nbr_len(n);
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	str[i--] = '\0';
	while (n > 0)
	{
		str[i--] = (char){n % 10 + 48};
		n /= 10;
	}
	return (str);
}