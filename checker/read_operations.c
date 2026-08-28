/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacpere <akacpere@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 19:13:58 by akacpere          #+#    #+#             */
/*   Updated: 2026/08/28 20:57:41 by akacpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static bool	update_stash(char **stash)
{
	char	*old_stash;
	int		i;
	int		j;

	old_stash = ft_strdup(*stash);
	free(*stash);
	i = 0;
	while (old_stash[i] != '\n')
		i++;
	i++;
	if (!old_stash[i])
	{
		*stash = NULL;
		return (free(old_stash), true);
	}
	*stash = ft_calloc(ft_strlen(*stash) - i + 1, sizeof(char));
	if (!*stash)
	{
		return (free(old_stash), false);
	}
	j = 0;
	while (old_stash[i])
		(*stash)[j++] = old_stash[i++];
	return (free(old_stash), true);
}

static bool	move_to_stash(char **stash, char *buffer)
{
	int	i;
	int	j;

	i = 0;
	while (buffer[i] != '\n')
		i++;
	i++;
	if (!buffer[i])
		return (true);
	*stash = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	if (!*stash)
		return (false);
	j = 0;
	while (buffer[i])
	{
		(*stash)[j] = buffer[i];
		j++;
		i++;
	}
	return (true);
}

static bool	read_stash(t_opr *opr, char **stash, t_stacks s)
{
	if (*stash)
	{
		if (!append(opr, *stash))
		{
			free(opr->opr);
			free(*stash);
			free_stacks_and_exit(s.stack_a, s.stack_b);
		}
		if (is_newline(opr->opr))
		{
			if (!update_stash(stash))
			{
				free(opr->opr);
				free(*stash);
				free_stacks_and_exit(s.stack_a, s.stack_b);
			}
			return (true);
		}
		free(*stash);
		*stash = NULL;
		return (false);
	}
	return (false);
}

static void	read_buffer(t_opr *opr, char **stash, char **buffer, t_stacks s)
{
	while (read(0, *buffer, 4))
	{
		if (!append(opr, *buffer))
		{
			free(opr->opr);
			free(*stash);
			free(*buffer);
			free_stacks_and_exit(s.stack_a, s.stack_b);
		}
		if (is_newline(opr->opr))
		{
			if (!move_to_stash(stash, *buffer))
			{
				free(opr->opr);
				free(*stash);
				free(*buffer);
				free_stacks_and_exit(s.stack_a, s.stack_b);
			}
			return ;
		}
		ft_bzero(*buffer, 4);
	}
	return ;
}

char	*read_operation(t_stacks s)
{
	t_opr		opr;
	static char	*stash = NULL;
	char		*buffer;

	opr.space = 1024;
	opr.size = 0;
	opr.opr = NULL;
	if (read_stash(&opr, &stash, s))
		return (opr.opr);
	buffer = ft_calloc(5, sizeof(char));
	if (!buffer)
	{
		free(opr.opr);
		free(stash);
		free_stacks_and_exit(s.stack_a, s.stack_b);
	}
	read_buffer(&opr, &stash, &buffer, s);
	free(buffer);
	return (opr.opr);
}
