#include "libft.h"

void	ft_bzero(void *ptr, size_t n)
{
	unsigned char	*pointer;
	size_t			i;

	i = 0;
	pointer = (unsigned char *)ptr;
	while (i < n)
		pointer[i++] = '\0';
}