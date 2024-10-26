#include <libft.h>
#include <so_long.h>

int	find_a_way(t_map *map)
{
	int		collectible;
	bool	exit_found;

	collectible = map->collectible;
	if (!set_visited(map))
		return (0);
	exit_found = false;
	map->exit_found = &exit_found;
	dfs(map, map->player_x, map->player_y);
	if (map->collectible > 0)
		return (ft_printf("Error: Not all collectibles are reachable!\n"), 0);
	if (*map->exit_found == false)
		return (ft_printf("Error: The exit is not reachable!\n"), 0);
	ft_free_matrix((void **)map->visited, map->rows);
	map->collectible = collectible;
	return (1);
}

int	check_each_char(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->cols - 1)
	{
		if (map->line[i] != '1' && map->line[i] != '0' && \
			map->line[i] != 'C' && map->line[i] != 'P' && \
			map->line[i] != 'E')
			return (ft_printf("Wrong character %c\n", map->line[i]), 0);
		if (map->line[i] == 'C')
			map->collectible++;
		else if (map->line[i] == 'E')
			map->exit++;
		else if (map->line[i] == 'P')
		{
			map->player_x = map->rows;
			map->player_y = i;
			map->position++;
		}
		i++;
	}
	return (1);
}

int	check_all_line(int fd, t_map *map)
{
	char	*tmp;

	map->rows = 0;
	while (1)
	{
		if (!map_clone(map))
			return (ft_printf("Memory allocation failed map_clone.\n"), 0);
		tmp = map->line;
		map->line = get_next_line(fd);
		if (!map->line)
		{
			map->line = tmp;
			map->rows++;
			break ;
		}
		map->rows++;
		free(tmp);
		if (!is_rectangular_walls(map, ft_strlen(map->line)))
			return (0);
		if (!check_each_char(map))
			return (0);
	}
	return (1);
}

int	map_check_up(int fd, t_map *map)
{
	map->line = get_next_line(fd);
	if (!map->line)
		return (ft_printf("Memory allocation failed map->line.\n"), 0);
	if (!check_up_first_last(map->line))
		return (0);
	map->cols = ft_strlen(map->line);
	if (!check_all_line(fd, map))
		return (0);
	if (map->collectible < 1 || map->exit != 1 || map->position != 1)
		return (ft_printf("Error: exit/position or collectible\n"), 0);
	if (!check_up_first_last(map->line))
		return (0);
	if (!find_a_way(map))
		return (0);
	return (1);
}

int	map_generator(const char *link, t_map *map)
{
	int			fd;
	bool		valid;

	map->map = NULL;
	valid = false;
	map->valid = &valid;
	fd = open(link, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error opening file\n"), 0);
	if (!map_check_up(fd, map))
	{
		free(map->line);
		ft_free_matrix((void *)map->map, map->rows);
		close(fd);
		return (0);
	}
	*map->valid = true;
	free(map->line);
	close(fd);
	return (1);
}
