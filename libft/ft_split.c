/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacpere <akacpere@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 15:32:02 by akacpere          #+#    #+#             */
/*   Updated: 2026/07/09 17:35:20 by akacpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	get_arr_size(char const *s, char c)
{
	unsigned int	size;
	int				is_word_beginning;
	unsigned int	i;

	if (!s)
		return (0);
	size = 0;
	is_word_beginning = 1;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			is_word_beginning = 1;
		if (s[i] != c && is_word_beginning)
		{
			size++;
			is_word_beginning = 0;
		}
		i++;
	}
	size++;
	return (size);
}

static	void	free_arr(char **arr)
{
	unsigned int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static char	*get_word_or_free(char **arr, const char *s, char c)
{
	unsigned int	i;
	char			*str;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	str = ft_calloc(1, i + 1);
	if (!str)
	{
		free_arr(arr);
		return (NULL);
	}
	i = 0;
	while (s[i] && s[i] != c)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char			**arr;
	int				is_word_beginning;
	unsigned int	i;

	arr = ft_calloc(get_arr_size(s, c), sizeof(char *));
	if (!arr || !s)
		return (NULL);
	is_word_beginning = 1;
	i = 0;
	while (*s)
	{
		if (*s == c && !is_word_beginning)
			is_word_beginning = 1;
		if (*s != c && is_word_beginning)
		{
			arr[i++] = get_word_or_free(arr, s, c);
			if (!arr)
				return (NULL);
			is_word_beginning = 0;
		}
		s++;
	}
	arr[i] = NULL;
	return (arr);
}
