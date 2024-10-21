
#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdbool.h>

typedef struct s_map
{
	char	*line;
	char	*last_line;
	char	*map;
	int		pos;
	int		exit;
	int		coll;
	int		first_len;
	int		current_len;
	int		cols;
	int		rows;
	int		player_x;
	int		player_y;
	bool	**visited;
	bool	*exit_found;
}	t_map;

typedef struct s_list
{
	void	*mlx;
	void	*win;
}				t_list;

int	map_generator(const char *map);
int	main(int argc, char **argv);
int	is_rectangular(t_map *map);
int	check_each_char(t_map *map);
int	map_clone(t_map *map);
void	dfs(t_map *map, int x, int y)

#endif
