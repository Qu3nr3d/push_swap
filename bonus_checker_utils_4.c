/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker_utils_4.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacpere <akacpere@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 18:50:16 by akacpere          #+#    #+#             */
/*   Updated: 2026/08/29 18:56:52 by akacpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_checker.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static int	word_len(char const *s, int i, char c)
{
	int	len;

	len = 0;
	while (s[i] && s[i++] != c)
		len++;
	return (len);
}

static void	free_all(char **res, int i)
{
	while (i >= 0)
	{
		free(res[i]);
		i--;
	}
	free(res);
}

static char	*get_word(char const *s, int *i, char c)
{
	char	*word;
	int		k;

	k = 0;
	word = malloc(sizeof(char) * (word_len(s, *i, c) + 1));
	if (!word)
		return (NULL);
	while (s[*i] && s[*i] != c)
		word[k++] = s[(*i)++];
	word[k] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	res = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!res)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			res[j] = get_word(s, &i, c);
			if (!res[j])
				return (free_all(res, j - 1), NULL);
			j++;
		}
		else
			i++;
	}
	res[j] = NULL;
	return (res);
}
