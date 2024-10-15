/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserhiei <dserhiei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 18:09:57 by dserhiei          #+#    #+#             */
/*   Updated: 2024/05/18 18:09:58 by dserhiei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;

	const
		unsigned char *s;
	d = dst;
	s = src;
	if (s < d)
	{
		while (len-- > 0)
			d[len] = s[len];
	}
	else
	{
		while (len-- > 0)
			*d++ = *s++;
	}
	return (dst);
}
