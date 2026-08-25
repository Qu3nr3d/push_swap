#include "checker.h"
#include <stdio.h>

// static bool str_is_equal(char *s1, char *s2)
// {
// 	int	i;

// 	i = 0;
// 	while (s1[i] && s2[i])
// 	{
// 		if (s1[i] != s2[i])
// 			return (0);
// 		i++;
// 	}
// 	if (s1[i] || s2[i])
// 		return (false);
// 	return (true);
// }

// static bool is_operation(char *s)
// {
// 	if (str_is_equal(s, "sa\n"))
// 		return (true);
// 	if (str_is_equal(s, "sb\n"))
// 		return (true);
// 	if (str_is_equal(s, "ss\n"))
// 		return (true);
// 	if (str_is_equal(s, "pa\n"))
// 		return (true);
// 	if (str_is_equal(s, "pb\n"))
// 		return (true);
// 	if (str_is_equal(s, "ra\n"))
// 		return (true);
// 	if (str_is_equal(s, "rb\n"))
// 		return (true);
// 	if (str_is_equal(s, "rr\n"))
// 		return (true);
// 	if (str_is_equal(s, "rra\n"))
// 		return (true);
// 	if (str_is_equal(s, "rrb\n"))
// 		return (true);
// 	if (str_is_equal(s, "rrr\n"))
// 		return (true);
// 	return (false);
// }

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

static void append_stash(char **operation, char *stash)
{
	int i;

	i = 0;
	while(stash[i])
	{
		(*operation)[i] = stash[i];
		i++;
	}
}

static void append_until_endline(char **operation, char *buffer, int index)
{
	int i;

	i = 0;
	while (buffer[i] != '\n')
		(*operation)[index++] = buffer[i++];
	(*operation)[index++] = '\n';
	(*operation)[index] = '\0';
}

static bool move_to_stash(char **stash, char *buffer, int *stash_size)
{
	int i;

	i = 0;
	if (*stash)
	{
		free(*stash);
		*stash_size = 0;
	}
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

bool	read_stdin(char **operation, int fd, bool *is_EOF)
{
	static char *stash = NULL;
	static int stash_size = 0;
	char *buffer;

	if (stash)
	{
		append_stash(operation, stash);
		if(is_newline(stash))
			return (true);
	}
	//printf("operation after adding stash: %s\n", *operation);
	buffer = ft_calloc(5, sizeof(char));
	if (!buffer)
		return (false);
	if (!read(fd, buffer, 4))
	{
		if (stash)
			free(stash);
		free(buffer);
		*is_EOF = true;
		return (true);
	}
	//printf("buffer: %s\n", buffer);
	if (!is_newline(buffer))
	{
		if (stash)
			free(stash);
		free(buffer);
		return (false);
	}
	append_until_endline(operation, buffer, stash_size);
	if (!move_to_stash(&stash, buffer, &stash_size))
	{
		free(buffer);
		return (false);
	}
	//printf("stash: %s\n", stash);
	free(buffer);
	return (true);
}
