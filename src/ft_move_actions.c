/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserhiei <dserhiei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:14:32 by dserhiei          #+#    #+#             */
/*   Updated: 2024/10/30 16:17:07 by dserhiei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <so_long.h>

int	chech_move(t_data *data, int x, int y)
{
	char	current;

	current = data->map->map[x][y];
	if (current == '1')
		return (0);
	else if (current == 'E' && data->map->collectible != 0)
	{
		ft_printf("You need to collect all flower!!\n");
		return (0);
	}
	else if (current == '0')
		data->map->map[x][y] = 'P';
	else if (current == 'C')
	{
		data->map->map[x][y] = 'P';
		data->map->collectible--;
	}
	else if (current == 'E' && data->map->collectible == 0)
	{
		ft_printf("You won!!\n");
		ft_close_window(data);
	}
	data->move_count++;
	printf("Move count: %d\n", data->move_count);
	return (1);
}

void	ft_move_player(t_data *data, int x, int y)
{
	if (!chech_move(data, x, y))
		return ;
	data->map->map[data->map->player_x][data->map->player_y] = '0';
	data->map->player_x = x;
	data->map->player_y = y;
	draw_map(data);
	return ;
}
