#include <libft.h>
#include <so_long.h>

void	ft_free_matrix(void **matrix, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(matrix[i++]);
	free(matrix);
}
