#include <../mlx_linux/mlx.h>
#include <libft.h>
#include <so_long.h>

int	main(int argc, char **argv)
{
	t_map	map;
	t_list	mlx;

	if (argc != 2)
		return (0);
	map = map_generator(argv[1]);
	if (!map.map)
	{
		ft_printf("The mape contains an error!\n");
		return (1);
	}
	mlx.mlx = mlx_init();
	mlx.w = 50;
	mlx.h = 50;
    mlx.win = mlx_new_window(mlx.mlx, 640, 480, "So Long Game");
	mlx.player = mlx_xpm_file_to_image(mlx.mlx, "./img/snail.xpm", &mlx.w, &mlx.h);
	mlx.wall = mlx_xpm_file_to_image(mlx.mlx, "./img/bush.xpm", &mlx.w, &mlx.h);
	mlx.collectible = mlx_xpm_file_to_image(mlx.mlx, "./img/flower.xpm", &mlx.w, &mlx.h);
	mlx.exit = mlx_xpm_file_to_image(mlx.mlx, "./img/home.xpm", &mlx.w, &mlx.h);
	mlx.empty = mlx_xpm_file_to_image(mlx.mlx, "./img/lake.xpm", &mlx.w, &mlx.h);

	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.player, 50, 50);

	mlx_loop(mlx.mlx);
}
