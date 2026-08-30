#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_itoa(int n);
void	ft_bzero(void *ptr, size_t n);
void	*ft_calloc(size_t n, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);