#include <libft.h>
#include <so_long.h>

int	check_each_char(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->current_len - 1)
	{
		if (map->line[i] != '1' && map->line[i] != '0' && \
			map->line[i] != 'C' && map->line[i] != 'P' && map->line[i] != 'E')
			return (ft_printf("Error wrong character %c\n", map->line[i]), 0);
		if (map->line[i] == 'C')
			map->coll++;
		else if (map->line[i] == 'E')
			map->exit++;
		else if (map->line[i] == 'P')
		{
			map->player_x = map->rows;
			map->player_y = i;
			map->pos++;
			if (!map->player_x || !map->player_y)
				return (ft_printf("Error: Player position not found!\n"), 0);
		}
		i++;
	}
	return (1);
}

int	is_rectangular(t_map *map)
{
	if (map->line[map->current_len - 1] == '\n')
	{
		if (map->cols == map->current_len)
			return (1);
	}
	else
	{
		if (map->cols == map->current_len + 1)
			return (1);
	}
	return (ft_printf("The map is not rectangular!\n"), 0);
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
	if (!map->coll && *map->exit_found)
		return ;
	if (x < 0 || y < 0 || x >= map->rows || y >= map->cols || \
		map->map[x * map->cols + y] == '1' || map->visited[x][y])
		return ;
	map->visited[x][y] = true;
	if (map->map[x * map->cols + y] == 'C')
		map->coll--;
	if (map->map[x * map->cols + y] == 'E')
		*map->exit_found = true;
	ft_printf("one more time: %d, %d \n", map->coll , *map->exit_found);
	dfs(map, x - 1, y);
	dfs(map, x + 1, y);
	dfs(map, x, y - 1);
	dfs(map, x, y + 1);
}
