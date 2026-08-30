#include "libft.h"

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