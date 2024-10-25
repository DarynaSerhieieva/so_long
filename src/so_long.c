#include <../mlx_linux/mlx.h>
#include <libft.h>
#include <so_long.h>

// void	draw_map(t_map	*map, t_list *mlx)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	y = 0;
// 	while (x < map->rows && y < map->cols)
// 	{
// 		if (map->map[x * map->cols + y] == '1')
// 			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->wall, y * 50, x * 50);
// 		else if (map->map[x * map->cols + y] == 'P')
// 			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->player, y * 50, x * 50);
// 		else if (map->map[x * map->cols + y] == 'C')
// 			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->collectible, y * 50, x * 50);
// 		else if (map->map[x * map->cols + y] == 'E')
// 			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->exit, y * 50, x * 50);
// 		else
// 			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->backgraund, y * 50, x * 50);
// 		y++;
// 		if (map->map[x * map->cols + y] == '\n')
// 		{
// 			x++;
// 			y = 0;
// 		}
// 	}
// }
void	draw_map(t_map *map, t_list *mlx)
{
	int x;
	int y;

	for (x = 0; x <= map->rows; x++)
	{
		for (y = 0; y < map->cols - 1; y++)
		{
			char current = map->map[x][y];
			ft_printf("current %c\n", current);
			if (current == '1')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->wall, y * 50, x * 50);
			else if (current == 'P')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->player, y * 50, x * 50);
			else if (current == 'C')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->collectible, y * 50, x * 50);
			else if (current == 'E')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->exit, y * 50, x * 50);
			else
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->backgraund, y * 50, x * 50);
		}
	}
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_list	mlx;
	int		w;
	int		h;

	map.collectible = 0;
	map.exit = 0;
	map.position = 0;
	if (argc != 2)
		return (0);
	map_generator(argv[1], &map);
	if (!*map.valid)
		return (1);
	w = 50;
	h = 50;
	mlx.mlx = mlx_init();
    mlx.win = mlx_new_window(mlx.mlx, (map.cols - 1 ) * 50, (map.rows + 1)* 50, "So Long Game");
	mlx.player = mlx_xpm_file_to_image(mlx.mlx, "./img/snail.xpm", &w, &h);
	mlx.wall = mlx_xpm_file_to_image(mlx.mlx, "./img/stone.xpm", &w, &h);
	mlx.collectible = mlx_xpm_file_to_image(mlx.mlx, "./img/flower.xpm", &w, &h);
	mlx.exit = mlx_xpm_file_to_image(mlx.mlx, "./img/home.xpm", &w, &h);
	mlx.backgraund = mlx_xpm_file_to_image(mlx.mlx, "./img/backgraund.xpm", &w, &h);
	draw_map(&map, &mlx);

	mlx_loop(mlx.mlx);
}
