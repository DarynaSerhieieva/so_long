
#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>

typedef struct s_map
{
	char	*line;
	char	*last_line;
	char	*map;
	char	*start;
	int		pos;
	int		exit;
	int		coll;
	int		first_len;
	int		current_len;
}	t_map;

typedef struct s_list
{
	void	*mlx;
	void	*win;
}				t_list;

int	map_generator(const char *map);
int	main(int argc, char **argv);
int	is_rectangular(t_map *map);
int	count_char(t_map *map, char c);
// int	map_clone(t_map *map);
// int	check_each_char(char *line, int len);

#endif
