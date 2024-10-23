#include <libft.h>
#include <so_long.h>

int	set_visited(t_map *map)
{
	int		i;

	i = 0;
	map->visited = (bool **)malloc(map->rows * sizeof(bool *));
	if (!map->visited)
		return (ft_printf("Memory allocation error!\n"), 0);
	while (i < map->rows)
	{
		map->visited[i] = (bool *)ft_calloc(map->cols, sizeof(bool));
		if (!map->visited[i])
			return (ft_printf("Memory allocation error!\n"), 0);
		i++;
	}
	return (1);
}

int	check_up_first_last(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1' && line[i] != '\n')
		{
			ft_printf("All line must contain only: 1\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	is_rectangular(t_map *map, int current_len)
{
	if (map->line[current_len - 1] != '\n')
		current_len++;
	if (map->cols != current_len)
	{
		ft_printf("The map is not rectangular!\n");
		return (0);
	}
	return (1);
}

int	map_clone(t_map *map)
{
	char	*temp;

	if (!map->map)
	{
		map->map = ft_strdup(map->line);
		if (!map->map)
			return (0);
	}
	else
	{
		temp = map->map;
		map->map = ft_strjoin(temp, map->line);
		free(temp);
		if (!map->map)
			return (0);
	}
	return (1);
}

void	dfs(t_map *map, int x, int y)
{
	if (map->collectible == 0 && *map->exit_found)
		return ;
	if (x < 0 || y < 0 || x >= map->rows || y >= map->cols)
		return ;
	if (map->map[x * map->cols + y] == '1' || map->visited[x][y])
		return ;
	map->visited[x][y] = true;
	if (map->map[x * map->cols + y] == 'C')
		map->collectible--;
	if (map->map[x * map->cols + y] == 'E')
		*map->exit_found = true;
	dfs(map, x - 1, y);
	dfs(map, x + 1, y);
	dfs(map, x, y - 1);
	dfs(map, x, y + 1);
}
