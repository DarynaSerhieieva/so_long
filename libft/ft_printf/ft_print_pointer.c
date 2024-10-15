/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserhiei <dserhiei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:23:20 by dserhiei          #+#    #+#             */
/*   Updated: 2024/10/06 19:12:24 by dserhiei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_pointer(void *ptr, int *leng)
{
	if (ptr == NULL)
	{
		ft_putstr_fd("(nil)", 1);
		*leng += 5;
	}
	else
	{
		ft_putstr_fd("0x", 1);
		*leng += 2;
		ft_puthex((uintptr_t)ptr, leng, 0);
	}
}
