/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserhiei <dserhiei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 18:10:01 by dserhiei          #+#    #+#             */
/*   Updated: 2024/05/18 18:10:02 by dserhiei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	uc;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	ptr = s;
	uc = (unsigned char)c;
	while (i < n)
	{
		ptr[i] = uc;
		i++;
	}
	return (s);
}
