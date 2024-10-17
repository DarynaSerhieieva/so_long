#include <../mlx_linux/mlx.h>
#include <libft.h>
#include <so_long.h>

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	if (map_render(argv[1]))
	{
		ft_printf("The map is correct!\n");
		return (0);
	}
	else
	{
		ft_printf("The mape contains an error!\n");
		return (1);
	}
}

/*typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	close(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

	t_vars	mlx;
	t_data	img;
	int i = 0;
	int j = 0;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	while (i != 100)
	{
		i++;
		j = 0;
		while (j != 100)
		{
			my_mlx_pixel_put(&img, i, j, create_trgb(1, 128, 128, 0));
			j++;
		}
		my_mlx_pixel_put(&img, i, j, create_trgb(1, 128, 128, 0));
	}
	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
	mlx_hook(mlx.win, 2, 1L<<0, close, &mlx);
	mlx_loop(mlx.mlx);*/
