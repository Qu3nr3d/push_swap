#include "checker.h"
#include <stdio.h>

static void initialize_operation_and_buffer(t_operation *opr, char **buffer)
{
	opr->capacity = 1024;
	opr->size = 0;
	opr->operation = NULL;
	*buffer = NULL;
}

static bool append(t_operation *opr, char *str)
{
	int i;

	i = 0;
	if (!opr->operation)
	{
		opr->operation = ft_calloc(opr->capacity, sizeof(char));
		if (!opr->operation)
			return (false);
	}
	while (str[i])
	{
		opr->operation[opr->size++] = str[i];
		if (opr->size == opr->capacity)
		{
			opr->operation = reallocate(opr->operation, opr->capacity, opr->capacity * 2);
			if (!opr->operation)
				return (false);
			opr->capacity *= 2;
		}
		if (str[i] == '\n')
			break;
		i++;
	}
	opr->operation[opr->size] = '\0';
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
		free(old_stash);
		*stash = NULL;
		return (true);
	}
	*stash = ft_calloc(old_stash_size - i + 1, sizeof(char));
	if (!*stash)
	{
		free(old_stash);
		return (false);
	}
	while (old_stash[i])
		(*stash)[*stash_size++] = old_stash[i++];
	free(old_stash);
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
	if (!buffer[i])
		return (true);
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

static void free_all(char **operation, char **stash, char **buffer)
{
	if (*operation)
	{
		free(*operation);
		*operation = NULL;
	}
	if (*stash)
	{
		free(*stash);
		*stash = NULL;
	}
	if (*buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
}

static void free_opr_and_buff(char **operation, char **buffer)
{
	if (*operation)
	{
		free(*operation);
		*operation = NULL;
	}
	if (*buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
}

bool	read_operation(char **str)
{
	t_operation opr;
	static char *stash = NULL;
	static int stash_size = 0;
	char *buffer;

	initialize_operation_and_buffer(&opr, &buffer);
	if (stash)
	{
		if (!append(&opr, stash))
			return (free_all(&opr.operation, &stash, &buffer), false);
		if(is_newline(opr.operation))
		{
			if (!update_stash(&stash, &stash_size))
				return (free_all(&opr.operation, &stash, &buffer), false);
			*str = ft_strdup(opr.operation);
			return (free_opr_and_buff(&opr.operation, &buffer), true);
		}
		free(stash);
		stash = NULL;
	}
	buffer = ft_calloc(5, sizeof(char));
	if (!buffer)
		return (free_all(&opr.operation, &stash, &buffer), false);
	while (read(0, buffer, 4))
	{
		if (!append(&opr, buffer))
			return (free_all(&opr.operation, &stash, &buffer), false);
		if (is_newline(opr.operation))
		{
			if (!move_to_stash(&stash, buffer, &stash_size))
				return (free_all(&opr.operation, &stash, &buffer), false);
			*str = ft_strdup(opr.operation);
			return (free_opr_and_buff(&opr.operation, &buffer), true);
		}
		ft_bzero(buffer, 4);
	}
	if (opr.operation)
		*str = ft_strdup(opr.operation);
	else
		*str = NULL;
	return (free_opr_and_buff(&opr.operation, &buffer), true);
}
