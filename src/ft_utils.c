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
	"./img/snail.xpm", &w, &h);
	data->mlx->wall = mlx_xpm_file_to_image(data->mlx->mlx, \
	"./img/stone.xpm", &w, &h);
	data->mlx->coll = mlx_xpm_file_to_image(data->mlx->mlx, \
	"./img/flower.xpm", &w, &h);
	data->mlx->exit = mlx_xpm_file_to_image(data->mlx->mlx, \
	"./img/home.xpm", &w, &h);
	data->mlx->grass = mlx_xpm_file_to_image(data->mlx->mlx, \
	"./img/grass.xpm", &w, &h);
}
