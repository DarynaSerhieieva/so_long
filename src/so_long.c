#include <../mlx_linux/mlx.h>
#include <libft.h>
#include <so_long.h>

void	draw_map(t_map *map, t_list *mlx)
{
	int		x;
	int		y;
	char	current;

	x = 0;
	while (x < map->rows)
	{
		y = 0;
		while (y < map->cols - 1)
		{
			current = map->map[x][y];
			if (current == '1')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->wall, y * mlx->h, x * mlx->w);
			else if (current == 'P')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->player, y * mlx->h, x * mlx->w);
			else if (current == 'C')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->coll, y * mlx->h, x * mlx->w);
			else if (current == 'E')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->exit, y * mlx->h, x * mlx->w);
			else
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->grass, y * mlx->h, x * mlx->w);
			y++;
		}
		x++;
	}
}

int	ft_close_window(t_list *mlx)
{
	ft_free_matrix((void **)mlx->map, mlx->size);
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit (0);
}

int	handle_key(int keycode, t_list *mlx)
{
	if (keycode == 65307)
	{
		ft_close_window(mlx);
	}
		
	// else if (keycode == 'W' || keycode == 119) // W key
	//     move_up();
	// else if (keycode == 'S' || keycode == 115) // S key
	//     move_down();
	// else if (keycode == 'A' || keycode == 97)  // A key
	//     move_left();
	// else if (keycode == 'D' || keycode == 100) // D key
	//     move_right();

	return (0);
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_list	mlx;

	map.collectible = 0;
	map.exit = 0;
	map.position = 0;
	map.rows = 0;
	if (argc != 2)
		return (0);
	map_generator(argv[1], &map);
	if (!*map.valid)
		return (1);
	mlx.map = map.map;
	mlx.size = map.rows;
	mlx.w = 50;
	mlx.h = 50;
	mlx.mlx = mlx_init();
    mlx.win = mlx_new_window(mlx.mlx, (map.cols - 1 ) * SIZE_IMG, map.rows * SIZE_IMG, "So_long");
	mlx.player = mlx_xpm_file_to_image(mlx.mlx, "./img/snail.xpm", &mlx.w, &mlx.h);
	mlx.wall = mlx_xpm_file_to_image(mlx.mlx, "./img/stone.xpm", &mlx.w, &mlx.h);
	mlx.coll = mlx_xpm_file_to_image(mlx.mlx, "./img/flower.xpm", &mlx.w, &mlx.h);
	mlx.exit = mlx_xpm_file_to_image(mlx.mlx, "./img/home.xpm", &mlx.w, &mlx.h);
	mlx.grass = mlx_xpm_file_to_image(mlx.mlx, "./img/grass.xpm", &mlx.w, &mlx.h);
	draw_map(&map, &mlx);
	mlx_key_hook(mlx.win, handle_key, &mlx);
	mlx_hook(mlx.win, 17, 0, ft_close_window, &mlx); 
	mlx_loop(mlx.mlx);
}
