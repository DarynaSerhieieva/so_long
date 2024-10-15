/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserhiei <dserhiei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 18:09:39 by dserhiei          #+#    #+#             */
/*   Updated: 2024/05/18 18:09:41 by dserhiei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int
	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	else
		return (num);
}

static int
	count_size(int n)
{
	int	i;
	int	clone;

	i = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648 || n == 2147483647)
		return (10);
	clone = n;
	if (n < 0)
		clone = -clone;
	while (clone > 0)
	{
		clone = clone / 10;
		i++;
	}
	return (i);
}

static void
	ft_strrev(char *str)
{
	size_t	length;
	size_t	i;
	char	tmp;

	length = ft_strlen(str);
	i = 0;
	while (i < length / 2)
	{
		tmp = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = tmp;
		i++;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		is_neg;
	int		n_len;
	size_t	length;

	is_neg = (n < 0);
	n_len = count_size(n);
	str = ft_calloc(n_len + 1 + is_neg, sizeof(*str));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	length = 0;
	while (n != 0)
	{
		str[length++] = '0' + ft_abs(n % 10);
		n = (n / 10);
	}
	if (is_neg)
		str[length] = '-';
	ft_strrev(str);
	return (str);
}
