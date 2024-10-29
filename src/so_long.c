#include <libft.h>
#include <so_long.h>

void	draw_map(t_data *data)
{
	int		x;
	int		y;
	char	current;

	x = 0;
	while (x < data->map->rows)
	{
		y = 0;
		while (y < data->map->cols - 1)
		{
			current = data->map->map[x][y];
			if (current == '1')
				mlx_img(data, data->mlx->wall, x * SIZE_IMG, y * SIZE_IMG);
			else if (current == 'P')
				mlx_img(data, data->mlx->player, x * SIZE_IMG, y * SIZE_IMG);
			else if (current == 'C')
				mlx_img(data, data->mlx->coll, x * SIZE_IMG, y * SIZE_IMG);
			else if (current == 'E')
				mlx_img(data, data->mlx->exit, x * SIZE_IMG, y * SIZE_IMG);
			else
				mlx_img(data, data->mlx->grass, x * SIZE_IMG, y * SIZE_IMG);
			y++;
		}
		x++;
	}
}

int	handle_key(int keycode, t_data *data)
{
	if (keycode == 65307)
		ft_close_window(data);
	else if (keycode == 'W' || keycode == 119)
		ft_move_player(data, data->map->player_x - 1, data->map->player_y);
	else if (keycode == 'S' || keycode == 115)
		ft_move_player(data, data->map->player_x + 1, data->map->player_y);
	else if (keycode == 'A' || keycode == 97)
		ft_move_player(data, data->map->player_x, data->map->player_y - 1);
	else if (keycode == 'D' || keycode == 100)
		ft_move_player(data, data->map->player_x, data->map->player_y + 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_list	mlx;
	t_data	data;

	map.collectible = 0;
	map.exit = 0;
	map.position = 0;
	map.rows = 0;
	data.move_count = 0;
	if (argc != 2)
		return (0);
	map_generator(argv[1], &map);
	if (!*map.valid)
		return (1);
	data.map = &map;
	data.mlx = &mlx;
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, \
	(map.cols - 1) * SIZE_IMG, map.rows * SIZE_IMG, "So_long");
	render_img(&data);
	draw_map(&data);
	mlx_key_hook(mlx.win, handle_key, &data);
	mlx_hook(mlx.win, 17, 0, ft_close_window, &data);
	mlx_loop(mlx.mlx);
}
