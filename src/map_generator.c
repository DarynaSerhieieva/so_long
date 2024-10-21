#include <libft.h>
#include <so_long.h>

int	find_a_way(t_map *map)
{
	int	x;
	int	y;
	map->visited = (bool **)malloc(map->rows * sizeof(bool *));
	for (int i = 0; i < map->rows; i++)
		map->visited[i] = (bool *)malloc(map->cols * sizeof(bool));

	for (int i = 0; i < map->rows; i++)
		for (int j = 0; j < map->cols; j++)
			map->visited[i][j] = false;

	map->exit_found = false;
	x = map->player_x;
	y = map->player_y;

	dfs(map, x, y);

	if (map->coll > 0)
		return (ft_printf("Error: Not all collectibles are reachable!\n"), 0);

	if (!map->exit_found)
		return (ft_printf("Error: The exit is not reachable!\n"), 0);

	for (int i = 0; i < map->rows; i++)
		free(map->visited[i]);
	free(map->visited);

	return (1);
}

int	check_up_first_last(t_map *map, int ind)
{
	char	*line;
	int		i;

	i = 0;
	if (ind)
		line = map->line;
	else
		line = map->last_line - 1;
	i = ft_strlen(line);
	while (line[i] != '\0' && i >= 0)
	{
		if (line[i] == '1')
			i--;
		else
			return (ft_printf("The map does not have walls\n"), 0);
	}
	return (1);
}

int	check_all_line(int fd, t_map *map)
{
	map->rows = 0;
	while (map->line != 0)
	{
		if (!map_clone(map))
			return (ft_printf("Error clone: Memory allocation failed.\n"), 0);
		map->last_line = ft_strdup(map->line);
		if (!map->last_line)
			return (0);
		free(map->line);
		map->line = get_next_line(fd);
		if (!map->line)
			break ;
		map->current_len = ft_strlen(map->line);
		if (!is_rectangular(map))
			return (0);
		if (map->line[0] != '1' || map->line[map->current_len - 2] != '1')
			return (ft_printf("The line does not have walls!\n"), 0);
		map->rows++;
		if (!check_each_char(map))
			return (0);
		free(map->last_line);
	}
	return (1);
}

int	map_check_up(int fd)
{
	t_map		map;

	map.coll = 0;
	map.exit = 0;
	map.pos = 0;
	map.line = get_next_line(fd);
	if (!map.line)
		return (0);
	if (!check_up_first_last(&map, 1))
		return (free(map.line), 0);
	map.first_len = ft_strlen(map.line);
	if (!check_all_line(fd, &map))
		return (free(map.last_line), free(map.line), 0);
	if (map.coll < 1 || map.exit != 1 || map.pos != 1)
		return (ft_printf("Error: exit/ position or collectible\n"), 0);
	if (!check_up_first_last(&map, 0))
		return (free(map.last_line), free(map.line), free(map.map), 0);
	free(map.line);
	free(map.last_line);
	find_a_way(&map);
	return (1);
}

int	map_generator(const char *link)
{
	int	fd;

	fd = open(link, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error opening file\n"), 0);
	if (!map_check_up(fd))
		return (close(fd), 0);
	close(fd);
	return (1);
}
