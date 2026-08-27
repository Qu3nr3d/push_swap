#include "checker.h"
#include <stdio.h>

static void initialize_operation_and_buffer(t_operation *operation, char **buffer)
{
	operation->capacity = 1024;
	operation->size = 0;
	operation->operation = NULL;
	*buffer = NULL;
}

static bool append(t_operation *operation, char *str)
{
	int i;

	i = 0;
	if (!operation->operation)
	{
		operation->operation = ft_calloc(operation->capacity, sizeof(char));
		if (!operation->operation)
			return (false);
	}
	while (str[i])
	{
		operation->size++;
		operation->operation[operation->size - 1] = str[i];
		if (operation->size == operation->capacity)
		{
			//reallocate nie robi mi free na operation->operation
			operation->operation = reallocate(operation->operation, operation->capacity, operation->capacity * 2);
			if (!operation->operation)
				return (false);
			operation->capacity *= 2;
		}
		if (str[i] == '\n')
		{
			operation->operation[operation->size] = '\0';
			return (true);
		}
		i++;
	}
	operation->operation[operation->size] = '\0';
	return (true);
}

static bool update_stash(char **stash, int *stash_size)
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
		free(*stash);
		*stash = NULL;
		return (true);
	}
	*stash = ft_calloc(old_stash_size - i + 1, sizeof(char));
	if (!*stash)
		return (false);
	while (old_stash[i])
		(*stash)[*stash_size++] = old_stash[i++];
	return (true);
}

static bool move_to_stash(char **stash, char *buffer, int *stash_size)
{
	int i;

	i = 0;
	*stash_size = 0;
	while (buffer[i] != '\n')
		i++;
	i++;
	*stash = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	if (!*stash)
		return (false);
	while (buffer[i])
	{
		(*stash)[*stash_size] = buffer[i];
		(*stash_size)++;
		i++;
	}
	return (true);
}


bool	read_operation(char **opr)
{
	t_operation operation;
	static char *stash = NULL;
	static int stash_size = 0;
	char *buffer;

	initialize_operation_and_buffer(&operation, &buffer);
	if (stash)
	{
		if (!append(&operation, stash))
		{
			free(stash);
			if (operation.operation)
				free(operation.operation);
			return (false);
		}
		if(is_newline(operation.operation))
		{
			if (!update_stash(&stash, &stash_size))
			{
				free(operation.operation);
				return (false);
			}
			*opr = ft_strdup(operation.operation);
			return (true);
		}
		free(stash);
		stash = NULL;
	}
	buffer = ft_calloc(5, sizeof(char));
	if (!buffer)
	{
		if (stash)
			free(stash);
		if (operation.operation)
			free(operation.operation);
		return (false);
	}
	while (read(0, buffer, 4))
	{
		if (!append(&operation, buffer))
		{
			if (stash)
				free(stash);
			free(buffer);
			if (operation.operation)
				free(operation.operation);
			return (false);
		}
		if (is_newline(operation.operation))
		{
			if (!move_to_stash(&stash, buffer, &stash_size))
			{
				free(buffer);
				free(operation.operation);
				return (false);
			}
			*opr = ft_strdup(operation.operation);
			return (true);
		}
		ft_bzero(buffer, 4);
	}
	*opr = ft_strdup(operation.operation);
	return (true);
}
