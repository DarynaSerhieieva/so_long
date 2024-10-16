#include <libft.h>

int	check_up_first(char	*line)
{
	while (*line != '\0')
	{
		if (*line != '1')
		{
			ft_printf("The map is not correct,the first line \
			should only contain border");
			return (0);
		}
		*line++;
	}
	free(line);
	return (1);
}

int	check_all_line(int fd, int size_first_line)
{
	char			*line;
	int				*count_p;
	int				*count_e;
	int				*count_c;
	int				*current_line_len;

	count_p = 0;
	count_e = 0;
	count_c = 0;
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			return (NULL);
		}
		current_line_len = ft_strlen(line);
		if (size_first_line != current_line_len)
		{
			free(line);
			ft_printf("The map is not rectangular!");
			return (0);
		}
		if (line[0] != '1' || line[*current_line_len] != '1')
		{
			free(line);
			ft_printf("The map does not have border!");
			return (0);
		}
		if (ft_strrchr(line, 'C'))
			count_c++;
		if (ft_strrchr(line, 'E'))
			count_e++;
		if (ft_strrchr(line, 'P'))
			count_p++;
	}
}

int	map_check_up(int fd)
{
	char		*line;
	int			size_first_line;

	size_first_line = 0;
	line = get_next_line(fd);
	if (!line)
	{
		free(line);
		return (NULL);
	}
	if (!check_up_first(line))
		return (0);
	size_first_line = ft_strlen(line);
	if (!check_all_line(fd, size_first_line))
		return (0);
	return (1);
}

int	map_render(char *map, t_list *d)
{
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error opening file");
		return (0);
	}
	if (map_check_up(fd))
		return (1);
	else
	{
		ft_printf("map is not correct");
		return (0);
	}
}
