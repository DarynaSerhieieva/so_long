/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserhiei <dserhiei@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 18:10:32 by dserhiei          #+#    #+#             */
/*   Updated: 2024/09/18 14:47:58 by dserhiei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str_dup;
	size_t	len;

	len = ft_strlen(s) + 1;
	str_dup = (char *)malloc(sizeof(*s) * len);
	if (str_dup == NULL)
		return (NULL);
	ft_strlcpy(str_dup, s, len + 1);
	return (str_dup);
}
