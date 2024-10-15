/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserhiei <dserhiei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 18:11:23 by dserhiei          #+#    #+#             */
/*   Updated: 2024/05/18 18:11:23 by dserhiei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	cheak_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed_str;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && cheak_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && cheak_set(s1[end - 1], set))
		end--;
	trimmed_str = (char *)malloc(end - start + 1);
	if (!trimmed_str)
		return (NULL);
	i = 0;
	while (start < end)
		trimmed_str[i++] = s1[start++];
	trimmed_str[i] = '\0';
	return (trimmed_str);
}
