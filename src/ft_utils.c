#include <libft.h>
#include <so_long.h>

int	ft_close_window(t_data *data)
{
	ft_free_matrix((void **)data->map->map, data->map->rows);
	mlx_destroy_window(data->mlx->mlx, data->mlx->win);
	exit (0);
}

void	ft_free_matrix(void **matrix, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(matrix[i++]);
	free(matrix);
}

void	render_img(t_data *data)
{
	int		w;
	int		h;

	w = SIZE_IMG;
	h = SIZE_IMG;
	data->mlx->player = mlx_xpm_file_to_image(data->mlx->mlx, \
	"./img_100/snail.xpm", &w, &h);
	data->mlx->wall = mlx_xpm_file_to_image(data->mlx->mlx, \
	"./img_100/stone.xpm", &w, &h);
	data->mlx->coll = mlx_xpm_file_to_image(data->mlx->mlx, \
	"./img_100/flower.xpm", &w, &h);
	data->mlx->exit = mlx_xpm_file_to_image(data->mlx->mlx, \
	"./img_100/home.xpm", &w, &h);
	data->mlx->grass = mlx_xpm_file_to_image(data->mlx->mlx, \
	"./img_100/grass.xpm", &w, &h);
}

void	mlx_img(t_data *data, void	*img, int x, int y)
{
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, img, y, x);
}
