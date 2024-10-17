#include <libft.h>
#include <so_long.h>

/*int	check_each_char(char *line, int len)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && len - 1 > i)
	{
		if (line[i] != '1' || line[i] != '0' || \
			line[i] != 'C' || line[i] != 'P' || line[i] != 'E')
		{
			ft_printf("The character is not correct: %c", line[i]);
			return (0);
		}
		i++;
	}
	return (1);
}*/

int	count_char(t_map *map, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->line[i] != '\0')
	{
		if (map->line[i] == c)
			j++;
		i++;
	}
	return (j);
}

int	is_rectangular(t_map *map)
{
	if (map->line[map->current_len - 1] == '\n')
	{
		if (map->first_len == map->current_len)
			return (1);
	}
	else
	{
		if (map->first_len == map->current_len + 1)
			return (1);
	}
	return (ft_printf("The map is not rectangular!\n"), 0);
}

// int	map_clone(t_map *map)
// {
// 	if (map->map)
// 	{
// 		map->map_clone = ft_strdup(map->map);
// 		if (!map->map_clone)
// 			return (0);
// 		free(map->map);
// 	}
// 	if (map->map_clone)
// 	{
// 		map->map = ft_strjoin(map->map_clone, map->line);
// 		if (!map->map)
// 			return (0);
// 		free(map->map_clone);
// 	}
// 	else
// 		map->map = ft_strdup(map->line);
// 	return (1);
// }
