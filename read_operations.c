/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_read_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacpere <akacpere@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 19:13:58 by akacpere          #+#    #+#             */
/*   Updated: 2026/08/31 15:16:22 by akacpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*update_stash(t_opr opr, char *buffer, t_stacks s)
{
	int	i;
	int j;
	char *new_stash;

	i = 0;
	while (buffer[i] != '\n')
		i++;
	i++;
	if (!buffer[i])
		return (NULL);
	new_stash = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	if (!new_stash)
	{
		free(opr.opr);
		free(buffer);
		free_stacks_and_exit(s.stack_a, s.stack_b);
	}
	j = 0;
	while (buffer[i])
		new_stash[j++] = buffer[i++];
	return (new_stash);
}

static bool	append(t_opr *opr, char *str)
{
	int	i;

	i = 0;
	if (!opr->opr)
	{
		opr->opr = ft_calloc(opr->space, sizeof(char));
		if (!opr->opr)
			return (false);
	}
	while (str[i])
	{
		opr->opr[opr->size++] = str[i];
		if (opr->size == opr->space)
		{
			opr->opr = ft_realloc(opr->opr, opr->space, opr->space * 2);
			if (!opr->opr)
				return (false);
			opr->space *= 2;
		}
		if (str[i] == '\n')
			break ;
		i++;
	}
	opr->opr[opr->size] = '\0';
	return (true);
}

static bool	read_stash(t_opr *opr, char **stash, t_stacks s)
{
	char *new_stash;
	
	new_stash = NULL;
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
			new_stash = update_stash(*opr, *stash, s);
			free(*stash);
			*stash = new_stash;
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
			free(*stash);
			*stash = update_stash(*opr, *buffer, s);
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
	buffer = NULL;
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
