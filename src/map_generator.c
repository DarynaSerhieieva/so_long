#include <libft.h>
#include <so_long.h>

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
	ft_printf("My map:\n%s\n", map->map);
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
		{
			ft_printf("The map does not have walls\n");
			return (0);
		}
	}
	return (1);
}

int	check_all_line(int fd, t_map *map)
{
	while (map->line != 0)
	{
		if (!map_clone(map))
			return (0);
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
			return (ft_printf("The map does not have walls!\n"), 0);
		map->coll += count_char(map, 'C');
		map->exit += count_char(map, 'E');
		map->pos += count_char(map, 'P');
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
	if (map.coll < 1)
		return (ft_printf("Error, collectible!The map has:%d\n", map.coll), 0);
	if (map.exit != 1)
		return (ft_printf("Error, exit! The map has:%d\n", map.exit), 0);
	if (map.pos != 1)
		return (ft_printf("Error, position! The map has:%d\n", map.pos), 0);
	if (!check_up_first_last(&map, 0))
		return (free(map.last_line), free(map.line), 0);
	free(map.line);
	free(map.last_line);
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
