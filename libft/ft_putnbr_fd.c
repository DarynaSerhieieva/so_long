/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserhiei <dserhiei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 18:10:13 by dserhiei          #+#    #+#             */
/*   Updated: 2024/05/18 18:10:13 by dserhiei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	clone;

	clone = n;
	if (clone < 0)
	{
		ft_putchar_fd('-', fd);
		clone *= -1;
	}
	if (clone > 9)
	{
		ft_putnbr_fd(clone / 10, fd);
		ft_putchar_fd(('0' + (clone % 10)), fd);
	}
	else
		ft_putchar_fd(clone + '0', fd);
}
