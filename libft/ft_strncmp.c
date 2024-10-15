/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserhiei <dserhiei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 18:11:12 by dserhiei          #+#    #+#             */
/*   Updated: 2024/05/18 18:11:12 by dserhiei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	diff;

	diff = 0;
	i = 0;
	while ((s1[i] != '\0') && (s2[i] != '\0')
		&& (diff == 0) && (i < n))
	{
		diff = (unsigned char)s1[i] - (unsigned char)s2[i];
		i++;
	}
	if ((diff == 0) && (i < n))
		diff = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (diff);
}
