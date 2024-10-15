/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserhiei <dserhiei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:23:37 by dserhiei          #+#    #+#             */
/*   Updated: 2024/10/06 19:12:33 by dserhiei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthex(uintptr_t num, int *leng, int is_upper)
{
	if (num >= 16)
	{
		ft_puthex(num / 16, leng, is_upper);
		ft_puthex(num % 16, leng, is_upper);
	}
	else
	{
		*leng += 1;
		if (num <= 9)
			ft_putchar_fd(num + '0', 1);
		else
		{
			if (is_upper)
				ft_putchar_fd(num - 10 + 'A', 1);
			else
				ft_putchar_fd(num - 10 + 'a', 1);
		}
	}
}
