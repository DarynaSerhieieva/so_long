/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_un_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserhiei <dserhiei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:23:43 by dserhiei          #+#    #+#             */
/*   Updated: 2024/10/06 19:12:36 by dserhiei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int
	count_size(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 2147483647)
		return (10);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_unitoa(unsigned int num)
{
	char	*num_str;
	int		len;

	len = count_size(num);
	num_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!num_str)
		return (0);
	num_str[len] = '\0';
	while (num != 0)
	{
		num_str[len - 1] = num % 10 + 48;
		num = num / 10;
		len--;
	}
	return (num_str);
}

void	ft_un_decimal(unsigned int num, int *leng)
{
	char	*num_str;

	if (num == 0)
	{
		*leng += 1;
		ft_putchar_fd('0', 1);
	}
	num_str = ft_unitoa(num);
	*leng += ft_strlen(num_str);
	ft_putstr_fd(num_str, 1);
	free(num_str);
}
