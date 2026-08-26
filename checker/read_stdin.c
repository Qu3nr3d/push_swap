#include "checker.h"
#include <stdio.h>

typedef struct s_operation {
	char	*operation;
	int		size;
	int		capacity;
} t_operation;


static bool is_newline(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (true);
		i++;
	}
	return (false);
}



static bool move_to_stash(char **stash, char *buffer, int *stash_size)
{
	int i;

	i = 0;
	*stash_size = 0;
	while (buffer[i] != '\n')
		i++;
	i++;
	*stash = ft_calloc(20, sizeof(char));
	//printf("stash size: %li\n", ft_strlen(buffer) - i + 1);
	//printf("stash pointer: %p\n", *stash);
	if (!*stash)
		return (false);
	while (buffer[i])
	{
		(*stash)[*stash_size] = buffer[i];
		(*stash_size)++;
		i++;
	}
	//printf("stash string: %s\n", *stash);
	return (true);
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

void *reallocate(void *ptr1, int prev_size, int new_size)
{
	void			*ptr2;
	unsigned char	*pointer1;
	unsigned char	*pointer2;
	int				i;
	int				size;
	
	i = 0;
	ptr2 = ft_calloc(new_size, sizeof(char));
	pointer1 = (unsigned char*) ptr1;
	pointer2 = (unsigned char*) ptr2;
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

void remake_stash(char **stash, int *stash_size)
{
	char *old_stash;
	int old_stash_size;
	int i;

	old_stash = ft_strdup(*stash);
	old_stash_size = *stash_size;
	*stash_size = 0;
	free(*stash);
	i = 0;
	while (old_stash[i] != '\n')
		i++;
	i++;
	if (!old_stash[i])
	{
		*stash = NULL;
		return ;
	}
	*stash = ft_calloc(old_stash_size - i + 1, sizeof(char));
	while (old_stash[i])
		(*stash)[*stash_size++] = old_stash[i++];
}

static void initialize_operation(t_operation *operation)
{
	operation->capacity = 1024;
	operation->size = 0;
	operation->operation = NULL;
}

static void append(t_operation *operation, char *str)
{
	int i;

	i = 0;
	if (!operation->operation)
		operation->operation = ft_calloc(operation->capacity, sizeof(char));
	while (str[i])
	{
		operation->operation[operation->size] = str[i];
		operation->size++;
		if (operation->size > operation->capacity)
		{
			operation->operation = reallocate(operation->operation, operation->capacity, operation->capacity * 2);
			operation->capacity *= 2;
		}
		if (str[i] == '\n')
		{
			operation->operation[operation->size] = '\0';
			return ;
		}
		i++;
	}
	operation->operation[operation->size] = '\0';
	return ;
}

char	*read_operation()
{
	t_operation operation;
	static char *stash = NULL;
	static int stash_size = 0;
	char *buffer;

	initialize_operation(&operation);
	if (stash)
	{
		append(&operation, stash);
		if(is_newline(operation.operation))
		{
			remake_stash(&stash, &stash_size);
			return (operation.operation);
		}
		stash = NULL;
	}
	//printf("operation after adding stash, beginning: %s\n", operation.operation);
	buffer = ft_calloc(5, sizeof(char));
	while (read(0, buffer, 4))
	{
		//printf("buffer: %s\n", buffer);
		//printf("buffer_len: %li\n\n", ft_strlen(buffer));
		append(&operation, buffer);
		if (is_newline(operation.operation))
		{
			move_to_stash(&stash, buffer, &stash_size);
			//printf("stash: %s\n", stash);
			return (operation.operation);
		}
		ft_bzero(buffer, 4);
	}
	return (operation.operation);
}

// 	//printf("buffer: %s\n", buffer);
// 	if (!is_newoperation(buffer))
// 	{
// 		if (stash)
// 			free(stash);
// 		free(buffer);
// 		return (false);
// 	}
// 	append(operation, buffer, stash_size);
// 	if (!move_to_stash(&stash, buffer, &stash_size))
// 	{
// 		free(buffer);
// 		return (false);
// 	}
// 	//printf("stash: %s\n", stash);
// 	free(buffer);
// 	return (true);
// }
