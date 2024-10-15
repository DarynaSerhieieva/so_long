/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserhiei <dserhiei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 18:10:24 by dserhiei          #+#    #+#             */
/*   Updated: 2024/05/18 18:10:26 by dserhiei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s == c)
		{
			if (in_word)
				in_word = 0;
		}
		else
		{
			if (!in_word)
			{
				count++;
				in_word = 1;
			}
		}
		s++;
	}
	return (count);
}

static char	*copy_word(const char *start, const char *end)
{
	size_t	word_len;
	size_t	i;
	char	*word;

	word_len = end - start;
	word = (char *)malloc(word_len + 1);
	i = 0;
	if (!word)
		return (NULL);
	while (i < word_len)
	{
		word[i] = start[i];
		i++;
	}
	word[word_len] = '\0';
	return (word);
}

char	**fill_result_array(char const *s, char **result, char c, size_t i)
{
	const char	*start;

	while (*s)
	{
		if (*s != c)
		{
			start = s;
			while (*s && *s != c)
				s++;
			result[i] = copy_word(start, s);
			if (!result[i])
			{
				while (i > 0)
					free(result[--i]);
				free(result);
				return (NULL);
			}
			i++;
		}
		else
			s++;
	}
	return (result);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	word_count;
	char	**result;

	i = 0;
	word_count = count_words(s, c);
	result = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	fill_result_array(s, result, c, i);
	result[word_count] = NULL;
	return (result);
}
