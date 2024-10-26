#include <libft.h>
#include <so_long.h>

void	ft_move_player(t_data *data, int x, int y)
{
	char	current;

	current = data->map->map[x][y];
	if (current == '1')
		return ;
	else if (current == 'E' && data->map->collectible != 0)
	{
		ft_printf("You need to collect all flower!!\n");
		return ;
	}
	else if (current == '0')
	{
		data->map->map[x][y] = 'P';
	}
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
	data->map->map[data->map->player_x][data->map->player_y] = '0';
	data->map->player_x = x;
	data->map->player_y = y;
	draw_map(data);
	return ;
}
