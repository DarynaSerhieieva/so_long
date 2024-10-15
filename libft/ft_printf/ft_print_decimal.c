/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserhiei <dserhiei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:22:55 by dserhiei          #+#    #+#             */
/*   Updated: 2024/10/06 19:12:18 by dserhiei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_decimal(int dec, int *leng)
{
	char	*str;

	str = ft_itoa(dec);
	*leng += ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
}
