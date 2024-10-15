/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserhiei <dserhiei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:23:31 by dserhiei          #+#    #+#             */
/*   Updated: 2024/10/06 19:12:30 by dserhiei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	var_type(va_list args, const char fmt, int *leng)
{
	if (fmt == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		(*leng)++;
	}
	else if (fmt == 's')
		ft_print_str(va_arg(args, char *), leng);
	else if (fmt == 'p')
		ft_print_pointer((va_arg(args, void *)), leng);
	else if (fmt == 'd' || fmt == 'i')
		ft_print_decimal((va_arg(args, int)), leng);
	else if (fmt == 'u')
		ft_un_decimal((va_arg(args, unsigned int)), leng);
	else if (fmt == 'x' || fmt == 'X')
		ft_print_num_hex((va_arg(args, unsigned int)), fmt, leng);
	else if (fmt == '%')
	{
		ft_putchar_fd('%', 1);
		(*leng)++;
	}
}

int	ft_printf(const char *fmt, ...)
{
	va_list		args;
	int			leng;

	leng = 0;
	va_start(args, fmt);
	while (*fmt)
	{
		if (*fmt != '%')
		{
			ft_putchar_fd(*fmt, 1);
			leng++;
		}
		else
		{
			fmt++;
			var_type(args, *fmt, &leng);
		}
		fmt++;
	}
	va_end(args);
	return (leng);
}
