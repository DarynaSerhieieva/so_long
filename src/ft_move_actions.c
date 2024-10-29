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
	return (1);

}

void	ft_move_player(t_data *data, int x, int y)
{
	if (!chech_move(data, x, y))
		return ;
	data->map->map[data->map->player_x][data->map->player_y] = '0';
	data->map->player_x = x;
	data->map->player_y = y;
	data->move_count++;
	printf("Move count: %d\n", data->move_count);
	draw_map(data);
	return ;
}
