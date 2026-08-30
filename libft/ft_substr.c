#include "libft.h"

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